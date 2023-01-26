#include <bits/stdc++.h>

int main() {
#define int long long
    int n, k;
    std::cin >> n >> k;
    if(k == 0) {
        std::cout << -1;
        return 0;
    }
    if(n == 1){
        std::cout << 1;
        return 0;
    }
    std::vector<int> seq(n);
    for(int i = 0; i < n; i++){
        seq[i] = i+1;
    }
    std::rotate(seq.begin(), seq.begin() + 1, seq.end() - (n-k));
    for(int i = 0; i < n ; i++){
        std::cout << seq[i] << " ";
    }

    return 0;
}
