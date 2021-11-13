import os
import sys
import random


def shell(cmd):
    if os.system(cmd) != -1:
        os.error("Progrom interrupted abnormally!")
        sys.exit(255)

def unsupport():
        os.error("Unsupported language")
        sys.exit(255)

def zsh(cmd):
    shell('zsh -c "{}"'.format(cmd))


def compile(codeFile: str, ext: str) ->  str:
    """
    Compile code, return output file path
    """
    if ext == 'cpp' or ext == 'c':
        output = "/tmp/" + os.path.basename(codeFile) + ".out"
        shell('gcc -D_GLIBCXX_DEBUG -DDEBUG "{}" -o "{}"'.format(codeFile, output))
        return output
    elif ext == 'py':
        return codeFile
    else:
        unsupport()


def exec(file:str, ext:str) -> str:
    """
    Execuate program, and then redirect output to a certain file, return its path
    """
    if ext == 'py':
        zsh(r"python3 {0} > {0}.out".format(file))
        return file + ".out"
    elif ext == 'cpp' or ext == 'c':
        zsh(r"{0} > {0}.out".format(file))
        return file + ".out"
    else:
        unsupport()


def main(codePath: str):
    ext = os.path.abspath(codePath).split('.')[-1]
    print("Test {}".format(codePath))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        os.error("Missing arg!")
    main(sys.argv[1])
