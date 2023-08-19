#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(int n) {
    std::string str = std::to_string(n);
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    
    return str == reversedStr;
}

int main() {
    int n;
    //std::cout << "请输入一个整数: ";
    std::cin >> n;
    while(n%10==0){
        n/=10;
    }
    if (isPalindrome(n)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
