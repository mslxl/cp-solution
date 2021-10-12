#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
void q1(){
    cout << "I love Luogu!";
}
void q2(){
    cout << 6 << ' ' << 4;
}
void q3(){
    cout << 14 / 4 << endl
         << 14 / 4 * 4 << endl
         << 14 % 4;
}
void q4(){
    cout<<std::fixed<<std::setprecision(3)<<1.0*500/3;
}
void q5(){
    cout << (260 + 220) / (20 + 12);
}
void q6(){
    cout << sqrt(6*6 + 9*9);
}
void q7(){
    cout << 110 << endl
         << 90 << endl
         << 0;
}
void q8(){
    double pi = 3.141593;
    int r = 5;
    cout << pi * 2 * r << endl
         << pi * r * r << endl
         << (4.0 / 3) * pi * pow(r,3);
}

void q9(){
    int peach = 1;
    int &p = peach;
    // 2
    for (int i = 0; i < 3; i++) {
        p += 1;
        p *= 2;
    }
    cout << peach;
}
void q10(){
    cout << 9;
}
void q11(){
    cout << (100.0 / 3);
}
void q12(){
    cout << (int)('M' - 'A' + 1) << endl
        << (char)('A' + 17);
}
void q13(){
    double pi = 3.141593;
    cout<<(int)(pow(4.0/3*pi*(4*4*4+10*10*10),1.0/3));
}
void q14(){
    cout << 50;
}
int main(int argc, char *argv[]) {
    std::vector<void(*)()> func = {&q1, &q2,&q3, &q4,&q5,&q6,&q7,&q8,&q9,&q10,&q11,&q12,&q13,&q14};
    int input;
    cin >> input;
    (*func[input-1])();
    return 0;
}
