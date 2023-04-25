#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int num_room, num_passage;
const int enter = 1;
int& goal = num_room;

struct Room {
    std::vector<std::pair<int, int>> edge;
    int distance = -1;
};

Room* room;

void bfs1() {
#ifdef DEBUG
    std::cout << "start bfs1" << std::endl;

#endif
    bool* vis = new bool[num_room + 1];
    memset(vis, false, (num_room + 1) * sizeof(bool));
    std::queue<int> queue;
    room[goal].distance = 0;
    queue.push(goal);
    vis[goal] = true;
    while (!queue.empty()) {
        const auto& current_room = room[queue.front()];
        queue.pop();
        for (const auto& edge : current_room.edge) {
            if (!vis[edge.first]) {
                auto& target = room[edge.first];
                target.distance = current_room.distance + 1;
                queue.push(edge.first);
                vis[edge.first] = true;
            }
        }
    }
    delete[] vis;
#ifdef DEBUG
    std::cout << "BFS1: " << std::endl;
    for (int i = 1; i <= num_room; i++) {
        std::cout << "Room " << i << " distance: " << room[i].distance
                  << std::endl;
    }
#endif
}

std::vector<int> bfs2() {
    std::vector<int> path;
    std::queue<int> queue;
    queue.push(1);

#ifdef DEBUG
    std::cout << "bfs2" << std::endl;
#endif

    while (!queue.empty()) {
        const auto& current_room = room[queue.front()];
        queue.pop();
        if (current_room.edge.size() == 1) {
            const auto& target = current_room.edge[0];
            if (current_room.distance - room[target.first].distance == 1) {
                queue.push(target.first);
                path.push_back(target.second);
            }
        } else if (current_room.edge.size() > 1) {
            int best_c = 10, best_target = -1;
            for (const auto& target : current_room.edge) {
                if (current_room.distance - room[target.first].distance == 1) {
                    if (target.second < best_c) {
                        best_c = target.second;
                        best_target = target.first;
                    }
                }
            }
            if (best_c != -1) {
                queue.push(best_target);
                path.push_back(best_c);
            }
        }
    }

    return path;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> num_room >> num_passage;
    room = new Room[num_room + 1];
    for (int i = 0; i < num_passage; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        room[a].edge.push_back(std::make_pair(b, c));
        room[b].edge.push_back(std::make_pair(a, c));
    }
    bfs1();
    const auto result = bfs2();
    const int size = static_cast<int>(result.size());
    std::cout << size << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << result[i];
        if (i != size - 1) {
            std::cout << ' ';
        }
    }
    delete[] room;
    return 0;
}
