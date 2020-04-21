import re

class Compiler(object):

    def compile(self, program):
        return self.pass3(self.pass2(self.pass1(program)))
        
    def tokenize(self, program):
        """Turn a program string into an array of tokens.  Each token
           is either '[', ']', '(', ')', '+', '-', '*', '/', a variable
           name or a number (as a string)"""
        token_iter = (m.group(0) for m in re.finditer(r'[-+*/()[\]]|[A-Za-z]+|\d+', program))
        return [tok for tok in token_iter]

    def pass1(self, program):
        tokens = self.tokenize(program)
        args = []
        list = []
        operators = []
        arg = False
        for t in tokens:
            if t == '[':
                arg = True
                continue
                
            if t == ']':
                arg = False
                continue
                
            if arg:
                args.append(t)
                continue
                
            if t in '+-*/':
                while(len(operators) != 0):
                    if operators[-1] != '(' and not (t in '*/' and operators[-1] in '+-'):
                        list.append(operators.pop())
                    else:
                        break
                operators.append(t)
            elif t == '(':
                operators.append(t)
            elif t == ')':
                while True:
                    x = operators.pop()
                    if x != '(' :
                        list.append(x)
                    else:
                        break
            else:
                list.append(t)
        
        stack = []
        for x in list + operators[::-1]:
            if x not in '+-*/':
                stack.append(x)
            else:
                b = self.build_val(stack.pop(), args)
                a = self.build_val(stack.pop(), args)
                stack.append({'op': x, 'a': a, 'b': b})
        
        return stack.pop()
        
    def build_val(self, val, args):
        if type(val) is dict:
            return val
        elif val in args:
            return {'op': 'arg', 'n': args.index(val)}
        elif val.isdigit():
            return {'op': 'imm', 'n': int(val)}
        
    def pass2(self, ast):
        if ast['op'] in '+-*/':
            if ast['a']['op'] in '+-*/':
                ast['a'] = self.pass2(ast['a'])
            if ast['b']['op'] in '+-*/':
                ast['b'] = self.pass2(ast['b'])
            if ast['a']['op'] == 'imm' and ast['b']['op'] == 'imm':
                ast = {'op': 'imm', 'n': eval(str(ast['a']['n']) + ast['op'] + str(ast['b']['n']))}
        
        return ast                

    def pass3(self, ast):
        op_dict = {
            '+': 'AD',
            '-': 'SU',
            '*': 'MU',
            '/': 'DI',
        }
        if ast['op'] in '+-*/':
            return (self.pass3(ast['a']) + self.pass3(ast['b'])) + ['PO', 'SW', 'PO', op_dict.get(ast['op']), 'PU']
        elif ast['op'] == 'arg':
            return ['AR ' + str(ast['n']), 'PU']
        elif ast['op'] == 'imm':
            return ['IM ' + str(ast['n']), 'PU']