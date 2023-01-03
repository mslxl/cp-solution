#include <iostream>
int main()
{
    long long x, n, t = 1;
    std::cin >> x >> n;
    while (n-- > 0)
    {
        t += x * t;
    }
    std::cout << t;
    return 0;
}