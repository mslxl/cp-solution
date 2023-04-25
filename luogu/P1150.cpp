#include <iostream>
int main()
{
    int n, k, s = 0,r = 0;
    std::cin >> n >> k;
    do
    {
        r %= k;
        s += n;
        r += n;
    } while ((n = r / k) != 0);
    std::cout << s;
    return 0;
}