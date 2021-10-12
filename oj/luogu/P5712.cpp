#include <iostream>
int main(int argc, char *argv[]) {
    int x;
    std::cin >> x;
    std::cout << "Today, I ate " << x << " apple";
    if(x >1)
        std::cout <<'s';
    std::cout <<".";
    return 0;
}
