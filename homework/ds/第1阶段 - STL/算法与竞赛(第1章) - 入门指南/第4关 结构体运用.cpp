//
//  main.cpp
//  step4
//
//  Created by ljpc on 2018/6/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include<cmath>

struct Point{
    double x, y;
    //  重载初始化函数
    Point(){x=y=0;}
    Point(double x_, double y_):x(x_), y(y_){}
    
    // 读入数据函数
    void in(){scanf("%lf %lf", &x, &y);}
    
    // 输出数据函数
    void out(){printf("%.2lf %.2lf\n", x, y);}
    
    // 重载 + 操作
    Point operator + (Point P){
        Point Q;
        Q.x = x + P.x;
        Q.y = y + P.y;
        return Q;
    }
    
    // 重载 - 操作
    Point operator - (Point P){
        Point Q = Point(0, 0);
        Q.x = x - P.x;
        Q.y = y - P.y;
        return Q;
    }
    
    // 重载 * 操作
    Point operator * (double scale){
        Point Q = Point(0, 0);
        Q.x = x * scale;
        Q.y = y * scale;
        return Q;
    }
    
};

// 计算面积
double area(Point p1, Point p2)
// 参数：矩形对角线上的两点p1(x1, y1), p2(x2, y2)
// 返回：矩形面积
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    double wid = std::abs(p2.x - p1.x);
    double hei = std::abs(p2.y-p1.y);
    return wid * hei;
    /********** End **********/
}

// 计算周长
double perimeter(Point p1, Point p2)
// 参数：矩形对角线上的两点p1(x1, y1), p2(x2, y2)
// 返回：矩形周长
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    double wid = std::abs(p2.x - p1.x);
    double hei = std::abs(p2.y-p1.y);
    return (wid + hei) * 2;

    /********** End **********/
}

// 计算中心点
Point center(Point p1, Point p2)
// 参数：矩形对角线上的两点p1(x1, y1), p2(x2, y2)
// 返回：矩形中心点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    double wid = std::abs(p2.x - p1.x);
    double hei = std::abs(p2.y-p1.y);
    double x = std::min(p1.x, p2.x);
    double y = std::min(p1.y, p2.y);
    return Point(x+wid/2, y + hei/2);
    /********** End **********/
}

int main(int argc, const char * argv[]) {
    
    
    // 1.读取数据
    Point p1, p2;
    p1.in();
    p2.in();
    
    // 2.运算分析
    Point pc = center(p1, p2);
    double s = area(p1, p2);
    double c = perimeter(p1, p2);
    
    // 3.输出结果
    printf("中心点 ");
    pc.out();
    
    printf("面积 %.2lf\n", s);
    
    printf("周长 %.2lf\n", c);
    
    
    return 0;
}
