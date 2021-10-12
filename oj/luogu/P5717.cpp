#include <cstdio>
#include <algorithm>
#include <cmath>
#define O(x) printf("%s triangle\n", x)
#define NT O("Not")
#define RT O("Right")
#define AT O("Acute")
#define OT O("Obtuse")
#define IT O("Isosceles")
#define ET O("Equilateral")

int main(int argc, char *argv[]) {
    int tri[3];
    scanf("%d %d %d", &tri[0], &tri[1], &tri[2]);
    std::sort(tri, tri + 3);
    if(tri[0] + tri [1] <= tri[2]) NT;
    else {
        if(pow(tri[0],2) + pow(tri[1],2) == pow(tri[2],2)) RT;
        else if(pow(tri[0],2) + pow(tri[1],2) > pow(tri[2],2)) AT;
        else if(pow(tri[0],2) + pow(tri[1],2) < pow(tri[2],2)) OT;
        if(tri[0] == tri[1] || tri[1] == tri[2]) IT;
        if(tri[0] == tri[1] && tri[1] == tri[2]) ET;
    }
    return 0;
}
