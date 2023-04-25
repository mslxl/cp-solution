#include <stdio.h>
#include <string.h>
int main(int argc, char const* argv[]) {
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    int tmp[3];

    memcpy(tmp, arr, 3 * sizeof(int));
    memcpy(arr, arr[1], 3 * sizeof(int));
    memcpy(arr[1], tmp, 3 * sizeof(int));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
