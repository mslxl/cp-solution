#include<bits/stdc++.h>
using ll = long long;
using ld = long double;

struct Rect{
    char pos_neg;
    ll value;

    bool operator<(const Rect& rhs)const {
        if(this->value == rhs.value){
            return this->pos_neg < rhs.pos_neg;
        }else{
            return this->value < rhs.value;
        }
    }
};

ll FalseNegative=0, TrueNegative=0;
ll TruePositive=0, FalsePositive=0;
ld ans = 0, LastX;


int main(){
    ll n;
    std::cin >> n;
    std::vector<Rect> seq(n);
    for(int i = 0; i < n; i++){
        std::cin >> seq[i].pos_neg >> seq[i].value;
        if(seq[i].pos_neg == '+'){
            FalseNegative++;
        }else{
            TrueNegative++;
        }
    }
    std::sort(seq.begin(), seq.end());

    for(int i = n-1; i >= 0; i--){
        if(seq[i].pos_neg == '+'){
            TruePositive++;
            FalseNegative--;
        }else{
            FalsePositive++;
            TrueNegative--;
        }
        ans += ld(TruePositive) / ld(TruePositive + FalseNegative) * (ld(FalsePositive) / (TrueNegative + FalsePositive) - LastX);
        LastX = ld(FalsePositive) / (TrueNegative + FalsePositive);
    }
    std::cout << std::setprecision(12) << std::fixed << ans;
}
