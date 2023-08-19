#include <iostream>
#include <vector>

bool canChange(std::vector<int>& bills) {
    int count25 = 0, count50 = 0;
    
    for (int bill : bills) {
        if (bill == 25) {
            count25++;
        } else if (bill == 50) {
            count25--;
            count50++;
        } else if (bill == 100) {
            if (count50 > 0) {
                count50--;
                count25--;
            } else {
                count25 -= 3;
            }
        }
        
        if (count25 < 0 || count50 < 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::vector<int> bills;
    int n;
    
    std::cin >> n;
    
    //std::cout << "请依次输入每个顾客支付的钞票面值（25, 50, 100）：" << std::endl;
    for (int i = 0; i < n; i++) {
        int bill;
        std::cin >> bill;
        bills.push_back(bill);
    }
    
    if (canChange(bills)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout <<"NO" << std::endl;
    }
    
    return 0;
}