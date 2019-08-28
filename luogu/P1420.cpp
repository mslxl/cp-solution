#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    int max = 0, curLen = 0, last = -2, cur;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cur;
        if (cur - last == 1)
        {
            curLen++;
            if(curLen > max){
                max = curLen;
            }
        } else {
            curLen = 0;
        }
        last = cur;
    }
    std::cout << max + 1;
}