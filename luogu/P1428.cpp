#include <iostream>
#include <cstring>

int main() {
    int fish_num;
    std::cin >> fish_num;
    int *fish_cute = new int[fish_num];
    int *fish_see = new int[fish_num];
    memset(fish_cute, 0, fish_num);
    memset(fish_see, 0, fish_num);
    for (int i = 0; i < fish_num; ++i)
        std::cin >> *(fish_cute + i);
    for (int viewer = fish_num - 1; viewer >= 0; --viewer) {
        int num = 0;
        for (int target = 0; target < viewer; ++target)
            if (*(fish_cute + viewer) > *(fish_cute + target))
                num++;
        *(fish_see + viewer) = num;
    }
    for (int i = 0; i < fish_num; ++i)
        std::cout << *(fish_see + i) << ' ';
}