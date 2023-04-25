//
//  main.cpp
//  step2
//
//  Created by ljpc on 2018/6/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    std::vector<int> seq(3);
    for(int i = 0; i < 3; i++) std::cin >> seq[i];
    std::sort(seq.begin(),seq.end());
    std::cout << seq[0];
    for(int i = 1; i < 3; i++) std::cout << " " << seq[i];
    std::cout << std::endl;
    
    /********** End **********/
    
    return 0;
}
