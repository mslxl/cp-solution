#include <stdio.h>
#include <stdlib.h>

int n;

int *arr;
int left = 0, len = 1;
int best_left = left, best_len = len;

int main(){
  int idx;
  scanf("%d", &n);
  arr = malloc(sizeof(int) * n);
  for(idx = 0; idx < n; idx++){
    scanf("%d", arr + idx);
  }

  while(left + len < n){
    if(arr[left + len] > arr[left+len-1]){
      len++;
      if(best_len < len){
        best_left = left;
        best_len = len;
      }
    } else{
      left len;
    }
  }

  for(idx = 0; idx < best_len; idx++){
    printf("%d ", arr[left + idx]);
  }
  printf("\n%d", len);

  free(arr);
  return 0;
}
