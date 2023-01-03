#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <string>

struct Pos {
    int row, col;
    int direction;
    Pos(int c = 0, int r = 0, int d = 0) : row(r), col(c), direction(d) {}
};

inline int get_turn_id(char c) {
    const static std::string turns("LFR");
    return turns.find(c) - 1;
}

inline int get_direction_id(char c) {
    const static std::string dirs("NESW");
    return dirs.find(c);
}

inline int turn_direction(int dir_id, int turn_id) {
    return (dir_id + turn_id + 4) % 4;
}

const int maxn = 10;
char maze_name[30];

int start_row, start_column, start_direction, goal_row, goal_column;
// X Y Direction Allowance(Left or Right)
// e.g. column kaj row
bool G[maxn][maxn][4][4];
bool vis[maxn][maxn][4];
Pos parent[maxn][maxn][5];

// Must be non-side effect
Pos walk(const Pos& pos, int turn) {
    int turned_dir = turn_direction(pos.direction, turn);
    const static int action[][2] = {
        {0, -1},  // North
        {1, 0},   // East
        {0, 1},   // South
        {-1, 0}   // West
    };
    auto select_act = action[turned_dir];
    return Pos(pos.col + select_act[0], pos.row + select_act[1], turned_dir);
}

inline bool has_edge(const Pos& pos, int turn) {
    auto simulate = walk(pos, turn);
    return G[pos.col][pos.row][pos.direction][turn + 1] &&
           !vis[simulate.col][simulate.row][simulate.direction];
}

void print_answer() {
    printf("%s\n", maze_name);
    std::stack<Pos> stack;
    Pos p = parent[goal_column][goal_row][2];
    while (p.col != start_column && p.row != start_row && p.direction != start_direction) {
        stack.push(p);
        p = parent[p.col][p.row][p.direction];
    }
    stack.push(Pos(start_column, start_row, 0));
    while (!stack.empty()) {
        p = stack.top();
        stack.pop();
        printf("(%d,%d) ", p.row, p.col);
    }
}

void bfs() {
    std::queue<Pos> queue;
    queue.push(Pos(start_column, start_row, start_direction));
    while (!queue.empty()) {
        auto cur_pos = queue.front();
        queue.pop();
        for (int turn = -1; turn <= 1; turn++) {
            // foreach in left, forward, right
            if (has_edge(cur_pos, turn)) {
                auto after = walk(cur_pos, turn);
                parent[after.col][after.row][after.direction] = cur_pos;
                vis[after.col][after.row][after.direction] = true;
                if (after.col == goal_column && after.row == goal_row) {
                    print_answer();
                    return;
                }
                queue.push(after);
            }
        }
    }
    printf("No Solution Possible\n");
}

void read_G_from_stdin() {
    memset(vis, false, sizeof(vis));
    memset(G, false, sizeof(G));
    char dir_tmp;

    scanf("%d%d %c%d%d", &start_row, &start_column, &dir_tmp, &goal_row,
          &goal_column);
    start_direction = get_direction_id(dir_tmp);
    G[start_column][start_row][start_direction][0 + 1] = true;

    int row, col;
    char wd[10];
    while (true) {
        scanf("%d", &row);
        if (row == 0)
            break;
        scanf("%d", &col);
        while (scanf("%s", wd) != 0 && wd[0] != '*') {
            int allow_dir = get_direction_id(wd[0]);
            for (int i = 1; i < strlen(wd); i++) {
                int allow_turn = get_turn_id(wd[i]);

                G[col][row][allow_dir][allow_turn + 1] = true;
            }
        }
    }
}

int main(int argc, char const* argv[]) {
    while (scanf("%s", maze_name) != 0 && strcmp(maze_name, "END") != 0) {
        read_G_from_stdin();
        bfs();
    }

    return 0;
}