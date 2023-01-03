#include <string>
#include <iostream>
int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        int sec = 0;
        int soc = 0;
        for (auto s:str){
            if(s == 'O'){
                soc += ++sec;
            }else{
                sec = 0;
            }
        }
        printf("%d", soc);
    }
    return 0;
}
