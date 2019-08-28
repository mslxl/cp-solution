#include <iostream>
int main()
{
    int n, uh = 0,sum = 0, a, b;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        uh = (a + b) - 8 + uh;
        sum += uh;
    }

    std::cout << sum;
    return 0;
}