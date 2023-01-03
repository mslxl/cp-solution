#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using std::string;

int main(int argc, char *argv[]) {
    string origion;
    std::cin >> origion;
    string min(origion);
    for (int i = 1; i < origion.size(); i++) {
        string new_str = origion.substr(i,origion.size()) + origion.substr(0,i);
        if(new_str < origion)
            min = new_str;
    }
    std::cout << min;

    return 0;
}
