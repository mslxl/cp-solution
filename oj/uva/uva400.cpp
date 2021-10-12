#include <iostream>
#include <string>
const int maxcol = 60;

void print(std::string *str, unsigned long lens, char extra){
    std::cout << *str;
    if(str->size() < lens){
        for (int i = 0; i < lens - str->size(); i++) {
            std::cout << extra;
        }
    }
}
int main(int argc, char *argv[]) {

    return 0;
}
