#include <cstdio>
#include <cstring>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(int argc, char *argv[]) {
    int i;
    while((i = getchar()) != EOF){
        char c = (char) i;
        if(c == ' '){
            putchar(' ');
            continue;
        }
        for (int index = 0; index < sizeof(s) / sizeof(char); index++) {
            if(s[index] == c){
                putchar(s[index-1]);
                break;
            }
        }
    }

    return 0;
}
