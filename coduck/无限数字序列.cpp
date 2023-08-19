#include <iostream>
#include <string>

int findDigit(int n) {
    // 将n转换为字符串，方便计算长度
    std::string number = std::to_string(n);
    
    // 计算当前数位范围的数字长度
    int len = 1, count = 9, start = 1;
    while (n > len * count) {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }
    
    // 找到对应的数字
    int target = start + (n - 1) / len;
    
    // 找到对应数字的第n位
    int digit = std::to_string(target)[(n - 1) % len] - '0';
    
    return digit;
}

int main() {
    int t;
    std::cin>>t;
    while(t--){
    int n;

    std::cin >> n;
    
    int digit = findDigit(n);
    
    std::cout << digit << std::endl;
    }
    return 0;
}