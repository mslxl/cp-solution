#include <iostream>

int main()
{
    int K;
    bool solved = false;
    std::cin >> K;
    for (auto i = 10000; i <= 30000; i++)
    {
        int sub1 = i / 100,
            sub2 = (i / 10) % 1000,
            sub3 = i % 1000;
        if(sub1 % K == 0 && sub2 % K == 0 && sub3 % K == 0){
            solved = true;
            std::cout << i << std::endl;
        }
    }
    if(!solved){
        std::cout << "No";
    }
    return 0;
}