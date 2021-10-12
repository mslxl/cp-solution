#include <cstdio>
#include <cmath>
#include <cstring>
int main(int argc, char *argv[]) {
    char c;
    int i;
    bool flag = true;
    while((i = getchar())!= EOF){
        c = (char) i;
        if (c == '"') {
            if(flag){
                printf("``");
            }else{
                printf("''");
            }
            flag = !flag;
        }else{
            printf("%c", c);
        }

    }
    return 0;
}
