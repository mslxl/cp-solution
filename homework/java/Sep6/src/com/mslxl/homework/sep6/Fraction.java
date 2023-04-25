package com.mslxl.homework.sep6;

import java.util.Scanner;

class MathUtil {
    public static int gcd(int a,int b){
        if(a%b==0)
            return b;
        return gcd(b,a%b);
    }
}

public class Fraction {
    int a,b;
    Fraction(int x,int y){
        this.a = x;
        this.b = y;
    }

    Fraction plus(Fraction r){
        Fraction ret = new Fraction(a* r.b + b * r.a, b * r.b);
        return ret;
    }
    Fraction mul(Fraction r){
        Fraction ret = new Fraction(a* r.a , b * r.b);
        return ret;
    }

    @Override
    public String toString() {
        int gcd = MathUtil.gcd(a,b);
        a/=gcd;
        b/=gcd;
        return String.format("%d/%d", a,b);
    }

    void print(){
        System.out.println(this);
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Fraction a = new Fraction(scanner.nextInt(), scanner.nextInt());
        Fraction b = new Fraction(scanner.nextInt(), scanner.nextInt());
        System.out.print("第一个分数为:");
        a.print();
        System.out.print("第二个分数为:");
        b.print();
        System.out.print("两个分数的和为:");
        a.plus(b).print();
        System.out.print("两个分数的积为:");
        a.mul(b).print();
    }
}
