#include<bits/stdc++.h>

int mx, my;
int ex, ey;
std::string route;

void solve() {
    std::cin >> mx >> my >> route;
    ex = ey = 0;
    int op[4] = {0, 0, 0, 0};
    for (int i = 0, len = route.size(); i < len; i++) {
        if (route[i] == 'U') {
            ey++;
            op[0]++;
        } else if (route[i] == 'D') {
            ey--;
            op[1]++;
        } else if (route[i] == 'L') {
            ex--;
            op[2]++;
        } else if (route[i] == 'R') {
            ex++;
            op[3]++;
        }
    }
    if ((ex == mx && ey == my) || (mx == 0 && my == 0)) {
        std::cout << "Impossible\n";
        return;
    }
    std::vector<int> flow = {0, 1, 2, 3};
    bool reachable = false;
    do {
        int x = 0, y = 0;
        for (auto cur_op: flow) {
            if(cur_op == 0){
                // U
                for(int t = 0; t < op[cur_op]; t++){
                    y++;
                    if(x == mx && y == my){
                        goto outter;
                    }
                }
            }else if(cur_op == 1){
                // D
                for(int t = 0; t < op[cur_op]; t++){
                    y--;
                    if(x == mx && y == my){
                        goto outter;
                    }
                }
            }else if(cur_op == 2){
                // L
                for(int t = 0; t < op[cur_op]; t++){
                    x--;
                    if(x == mx && y == my){
                        goto outter;
                    }
                }
            }else if(cur_op == 3){
                // R
                for(int t = 0; t < op[cur_op]; t++){
                    x++;
                    if(x == mx && y == my){
                        goto outter;
                    }
                }
            }
        }
        reachable = true;
        break;

        outter:
        int _unused;
    } while (std::next_permutation(flow.begin(), flow.end()));
    if(reachable){
        for(auto cur_op: flow){
            for(int t = 0; t < op[cur_op]; t++){
                if(cur_op == 0){
                    std::cout << "U";
                }else if(cur_op == 1){
                    std::cout << "D";
                }else if(cur_op == 2){
                    std::cout << "L";
                }else if(cur_op == 3){
                    std::cout << "R";
                }
            }
        }
        std::cout << "\n";
    }else{
        std::cout << "Impossible\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}