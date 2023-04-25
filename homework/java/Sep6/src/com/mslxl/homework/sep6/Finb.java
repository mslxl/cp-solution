package com.mslxl.homework.sep6;

import java.util.Scanner;

public class Finb {
    private int k;
    private int arr[];
    private int fibs(int idx){
        if(arr[idx] != 0) return arr[idx];

        if(idx == 1 || idx == 2) {
            arr[idx] = 1;
        }else{
            arr[idx] = fibs(idx-1) + fibs(idx-2);
        }

        return arr[idx];
    }
    void fibo(){
        arr = new int[k+1];
        fibs(k);
    }

    void fiboShow(){
        System.out.printf("fibs 的前 %d 项为\n", k);
        for(int i = 0; i < k; i++){
            System.out.printf("f%d=%d\t\t", i+1, arr[i]);
            if((i+1)%5 == 0) System.out.println();
        }
    }

    public static void main(String[] args) {
        Finb fibs= new Finb();
        System.out.print("请输入1个int类型数: k=");
        Scanner scanner = new Scanner(System.in);
        fibs.k = scanner.nextInt();
        fibs.fibo();
        fibs.fiboShow();
    }
}
