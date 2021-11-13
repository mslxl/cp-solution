#include <cstdio>
#include <cstring>

int N;
// const int MAX_N = 10;
const int MAX_N = 114514;
int studentsInCircle[MAX_N];

int leaveStudent[MAX_N];
int leaveCount = 0;

int studentFriendNum[MAX_N];

template <typename T>
inline T max(T& a, T& b) {
    return a > b ? a : b;
}

int find_and_remove_student_from_circle(int num) {
    int curNode = 0;

    while (num != 1) {
        curNode = studentsInCircle[curNode];
        num--;
    }

    int key = studentsInCircle[curNode];
    int nextNode = studentsInCircle[key];
    studentsInCircle[curNode] = nextNode;
    return key;
}

int main(int argc, char const* argv[]) {
    scanf("%d", &N);
    for (int idx = 0; idx <= N; idx++) {
        studentsInCircle[idx] = idx + 1;
    }
    studentsInCircle[N] = 1;

    int leave;
    for (int i = 0; i < N; i++) {
        scanf("%d", &leave);
        int outStu = find_and_remove_student_from_circle(leave);
        leaveStudent[leaveCount++] = outStu;
    }
    // memset(studentFriendNum, 0, sizeof(int) * N);

    int aheadFriend;
    int maxFrinend = 1;
    for (int i = 0; i < N; i++) {
        scanf("%d", &aheadFriend);
        if (aheadFriend != 0) {
            for (int j = aheadFriend; j > 0; j--) {
                int a = ++studentFriendNum[leaveStudent[i - j]];
                int b = ++studentFriendNum[leaveStudent[i]];
                int tmpMax;
                if ((tmpMax = max(a, b)) > maxFrinend) {
                    maxFrinend = tmpMax;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d %s\n", studentFriendNum[i],
               studentFriendNum[i] == maxFrinend ? "Yes" : "No");
    }

    return 0;
}