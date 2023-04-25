#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;

std::queue<int> que;
std::map<int, int> teams;
std::map<int, std::queue<int>> teams_que;

int main(int argc, char const *argv[]){
    std::ios::sync_with_stdio(false);
    int team_num;
    int scenario = 1;
    while(std::cin >> team_num && team_num != 0){

        for (int i = 0; i < team_num; i++)
        {
            int player_num;
            std::cin >> player_num;
            for (int j = 0; j < player_num; j++)
            {
                int player;
                std::cin >> player;
                teams[player] = i;
            }
        }
        std::cout << "Scenario #" << scenario++ << std::endl;
        std::string cmd;
        while(std::cin >> cmd && cmd[0] != 'S'){
            if(cmd[0] == 'E'){
                int player;
                std::cin >> player;
                int id_team = teams[player] ;
                if(!teams_que.count(id_team)){
                    teams_que[id_team] = std::queue<int>();
                    que.push(id_team);
                }
                teams_que[id_team].push(player);
            } else if(cmd[0] == 'D'){
                int id_team = que.front();
                std::queue<int> &tq = teams_que[id_team];
                std::cout << tq.front() << std::endl;
                tq.pop();
                if(tq.empty()){
                    que.pop();
                    teams_que.erase(id_team);
                }
            }
        }
        std::cout << std::endl;
        teams.clear();
        teams_que.clear();
        que = std::queue<int>();
    }
    
    return 0;
}