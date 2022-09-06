package com.mslxl.homework.sep6;

import java.util.Scanner;

public class Calculator {
    private double x, y;
    double add_ab(){
        return x+y;
    }
    double sub_ab(){
        return x-y;
    }
    double multi_ab(){
        return x*y;
    }
    double div_ab(){
        if(y==0) throw new ArithmeticException("除数不能为 零");
        return x/y;
    }
    void calc(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入第一个数: ");
        x = scanner.nextDouble();
        System.out.print("请输入第二个数: ");
        y = scanner.nextDouble();
        System.out.print("请输入操作符: ");
        char c =  scanner.next().trim().charAt(0);
        switch(c){
            case '+':
                System.out.printf("x + y = %s", add_ab());
                break;
            case '-':
                System.out.printf("x - y = %s", sub_ab());
                break;
            case '*':
                System.out.printf("x * y = %s", multi_ab());
                break;
            case '/':
                try{
                    System.out.printf("x / y = %s", div_ab());
                }catch(ArithmeticException e){
                    System.err.println(e.getMessage());
                }

                break;
            default:
                System.err.println("错误的运算符");
        }
    }

    public static void main(String[] args) {
        Calculator calc = new Calculator();
        calc.calc();
    }
}
