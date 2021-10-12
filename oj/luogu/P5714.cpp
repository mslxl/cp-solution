#include <cstdio>
#include <iostream>
int main(int argc, char *argv[]) {
    double m, h;
    scanf("%lf %lf", &m, &h);
    double bmi = m / (h * h);
    if(bmi < 18.5) printf("Underweight");
    else if(bmi > 24) std::cout << bmi << std::endl << "Overweight";
    else printf("Normal");
    return 0;
}
