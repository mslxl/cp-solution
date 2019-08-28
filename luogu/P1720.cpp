#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
  
    return 0;
}