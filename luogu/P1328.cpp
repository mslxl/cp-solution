#include <iostream>

int mapping[5][5] = {
        {
            0,-1,1,1,-1
        },
        {
            1,0,-1,1,-1
        },
        {
            -1,1,0,-1,1
        },
        {
            -1,-1,1,0,1
        },
        {
            1,1,-1,-1,0
        }
};

int Sa = 0,Sb = 0;

void match(int A,int B){
    int result = mapping[A][B];
    if (result == 1) {
        Sa++;
    }else if(result == -1){
        Sb++;
    }
}

int main(){
    int Times,Na,Nb;
    std::cin >> Times >> Na >> Nb;
    int Ra[Na],Rb[Nb];
    for (int i = 0; i < Na; ++i)
        std::cin >> Ra[i];
    for (int j = 0; j < Nb; ++j)
        std::cin >> Rb[j];

    int indexA = 0,indexB = 0;
    for (int k = 0; k < Times; ++k) {
        match(Ra[indexA],Rb[indexB]);
        indexA++;
        indexB++;
        if (indexA >= Na)
            indexA = 0;
        if (indexB >= Nb)
            indexB = 0;
    }
    std::cout << Sa << " " << Sb;
    return 0;
}