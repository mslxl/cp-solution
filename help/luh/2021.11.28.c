#include <stdio.h>
#include <stdlib.h>
void Readinfo(long num[], int score[], char name[][10], int n);
void Printinfo(long num[], int score[], char name[][10], int n);
void SwapName(char a[10], char b[10]);
void SwapNum(long* x, long* y);
void SwapScore(int* m, int* n);
void SelectionSort(long num[],
                   int score[],
                   char name[][10],
                   int n,
                   int (*compare)(int a, int b));
int Descending(int a, int b);
int Ascending(int a, int b);

int main() {
    long num[40];
    int score[40];
    char name[40][10];
    int n, in;
    printf("请输入班级人数：");
    scanf("%d", &n);
    Readinfo(num, score, name, n);
    do {
        printf("任务1: 输出\n");
        printf("任务2: 降序\n");
        printf("任务3: 升序\n");
        printf("输入1-3选择执行的任务,输入0退出：");
        scanf("%d", &in);
        switch (in) {
            case 1:
                Printinfo(num, score, name, n);
                break;
            case 2:
                SelectionSort(num, score, name, n, Descending);
                Printinfo(num, score, name, n);
                break;
            case 3:
                SelectionSort(num, score, name, n, Ascending);
                Printinfo(num, score, name, n);
                break;
            case 0:
                return 0;
            default:
                printf("Input Error!\n");
        }
    } while (1);
}

/*录入每个学生的学号、姓名和考试成绩*/
void Readinfo(long num[], int score[], char name[][10], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("请输入学号：\n");
        scanf("%ld", &num[i]);
        getchar();
        printf("请输入姓名：\n");
        gets(name[i]);
        printf("请输入成绩：\n");
        scanf("%d", &score[i]);
    }
}

/*输出每个学生的学号、姓名、考试成绩*/
void Printinfo(long num[], int score[], char name[][10], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("学号：%ld\n", num[i]);
        printf("姓名：%s\n", name[i]);
        printf("成绩：%d\n", score[i]);
    }
}

/*交换*/
void SwapName(char a[10], char b[10]) {
    char temp[10];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
void SwapNum(long* x, long* y) {
    long temp1;
    temp1 = *x;
    *x = *y;
    *y = temp1;
}
void SwapScore(int* m, int* n) {
    int temp2;
    temp2 = *m;
    *m = *n;
    *n = temp2;
}

/*排序*/
void SelectionSort(long num[],
                   int score[],
                   char name[][10],
                   int n,
                   int (*compare)(int a, int b)) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if ((*compare)(score[j], score[k]))
                k = j;
        }
        if (k != j) {
            SwapNum(&num[k], &num[i]);
            SwapName(name[k], name[i]);
            SwapScore(&score[k], &score[i]);
        }
    }
}

/*降序*/
int Descending(int a, int b) {
    return a > b;
}

/*升序*/
int Ascending(int a, int b) {
    return a < b;
}
