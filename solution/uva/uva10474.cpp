#include <cstdio>
#include <iostream>
#include <algorithm>

int main()
{
    int m, q;
    int case_index = 0;
    while (std::cin >> m >> q && m != 0 && q != 0) {
        int* marble = new int[m];
        for (int i = 0; i < m; i++)
            std::cin >> *(marble + i);
        std::sort(marble, marble + m);
        std::cout << "CASE# " << ++case_index << ":" << std::endl;
        for (int i = 0; i < q; i++)
        {
            int item;
            std::cin >> item;
            std::cout << item << " ";
            int pos = 0;
            for (int j = 0; j < m; j++)
            {
                if (item == marble[j]) {
                    pos = j + 1;
                    break;
                }
            }
            if (pos == 0) {
                std::cout << "not found" << std::endl;
            }
            else {
                std::cout << "found at " << pos << std::endl;
            }
        }
        delete[] marble;
    }
    return 0;
}
