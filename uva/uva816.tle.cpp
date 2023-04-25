#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
typedef int turn_id;
typedef int direction_id;
inline turn_id get_turn_id(char turn) {
    const static std::string turns("LFR");
    return turns.find(turn);
}
inline direction_id get_dir_id(char dir) {
    const static std::string dirs("NESW");
    return dirs.find(dir);
}

struct position {
    int row, col;
    direction_id direction;
    position() : row(0), col(0), direction(0) {}
    position(int r, int c, direction_id dir_id)
        : row(r), col(c), direction(dir_id) {}

    bool operator==(const position& rhs) const {
        return this->row == rhs.row && this->col == rhs.col &&
               this->direction == rhs.direction;
    }
};

std::string maze_name;
const int maxn = 10;
// [row][col][direction_id][turn_id]
bool edge[maxn][maxn][5][4];
// [row][col][direction_id]
position parent[maxn][maxn][5];
// [row][col][direction_id]
bool vis[maxn][maxn][5];

int start_col, start_row;
int start_dir;
int end_col, end_row;
int end_dir;  // Save when bfs end

const int TURN_LEFT = 0;
const int TURN_FORWARD = 1;
const int TURN_RIGHT = 2;

bool read_graph() {
    memset(edge, false, sizeof(edge));
    memset(vis, false, sizeof(vis));

    // Read meta data
    std::cin >> maze_name;
    if (maze_name == "END") {
        return false;
    }
    std::cin >> start_row >> start_col;

    std::string dir;
    std::cin >> dir;
    start_dir = get_dir_id(dir[0]);

    std::cin >> end_row >> end_col;
    // Start read route
    while (true) {
        int row, col;
        std::cin >> row;
        if (row == 0)
            break;
        std::cin >> col;
        while (std::cin >> dir && dir != "*") {
            const direction_id direction = get_dir_id(dir[0]);
            for (int idx = 1; idx < dir.size(); idx++) {
                const turn_id id = get_turn_id(dir[idx]);
                edge[row][col][direction][id] = true;
            }
        }
    }
    return true;
}

inline direction_id turn_dir(const direction_id& before_dir, turn_id turn) {
    return (before_dir + (turn - 1) + 4) % 4;
}

position walk(const position& pos, turn_id turn) {
    static int action[][2] = {/* North 0 */ {-1, 0},
                              /* East 1 */ {0, 1},
                              /* South 2*/ {1, 0},
                              /* West 3 */ {0, -1}};

    const direction_id dir = turn_dir(pos.direction, turn);
    const auto sel = action[dir];
    return position(pos.row + sel[0], pos.col + sel[1], dir);
}

inline bool has_edge(const position& pos, turn_id turn) {
    auto next = walk(pos, turn);
    return edge[pos.row][pos.col][pos.direction][turn] &&
           !vis[next.row][next.col][next.direction];
}

bool bfs() {
    std::queue<position> queue;
    auto start_pt = position(start_row, start_col, start_dir);
    auto real_start_pt = walk(start_pt, TURN_FORWARD);
    parent[real_start_pt.row][real_start_pt.col][real_start_pt.direction] =
        start_pt;
    queue.push(real_start_pt);

    if (real_start_pt.row == end_row && real_start_pt.col == end_col) {
        parent[real_start_pt.row][real_start_pt.col][real_start_pt.direction] =
            start_pt;
        end_dir = real_start_pt.direction;
        return true;
    }
    while (!queue.empty()) {
        const position current_position = queue.front();
        queue.pop();
        // Mark as visited
        vis[current_position.row][current_position.col]
           [current_position.direction] = true;
        for (int turn = TURN_LEFT; turn <= TURN_RIGHT; turn++) {
            if (has_edge(current_position, turn)) {
                const position next_position = walk(current_position, turn);
                // Mark child node
                parent[next_position.row][next_position.col]
                      [next_position.direction] = current_position;
                if (next_position.row == end_row &&
                    next_position.col == end_col) {
                    end_dir = next_position.direction;
                    return true;
                }
                queue.push(next_position);
            }
        }
    }
    return false;
}
void accept() {
    std::cout << maze_name;
    std::stack<position> stack;
    position pos(end_row, end_col, end_dir);
    stack.push(pos);
    position empty(0, 0, 0);
    while (true) {
        auto newPos = parent[pos.row][pos.col][pos.direction];
        parent[pos.row][pos.col][pos.direction] = empty;
        pos = newPos;
        // TODO here a bug existed

        if (pos.row == start_row && pos.col == start_col &&
            pos.direction == start_dir &&
            parent[pos.row][pos.col][pos.direction] == empty) {
            break;
        }
        stack.push(pos);
    }

    stack.push(position(start_row, start_col, 0));
    int cnt = 0;
    while (!stack.empty()) {
        pos = stack.top();
        stack.pop();
        if (cnt % 10 == 0) {
            std::cout << std::endl << " ";
        }
        std::cout << " (" << pos.row << ',' << pos.col << ")";
        cnt++;
    }
    std::cout << std::endl;
}
inline void reject() {
    std::cout << maze_name << std::endl;
    std::cout << "  No Solution Possible" << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    while (read_graph())
        bfs() ? accept() : reject();
}