#include <iostream>

int n, m;
int arr[1000001] = {0};

int find_v(int v, int left, int right) {
    if (left >= right) {
        if (v == arr[left]) {
            return left + 1;
        } else {
            return -1;
        }
    }
    int mid = left + (right - left) / 2;
    int mid_v = arr[mid];

    if (v <= mid_v) {
        return find_v(v, left, mid);
    } else {
        return find_v(v, mid + 1, right);
    }
}
int main() {
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        int v;
        std::cin >> v;
        std::cout << find_v(v, 0, n) << ' ';
    }
}
