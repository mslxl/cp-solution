#include<cstdio>
#include<cstring>
#include<algorithm>

char N[260];
int k;

int find_min(int start_pos, int end_pos){
  int min_pos = start_pos;
  char min = N[start_pos];
  for(int i = start_pos + 1; i < end_pos; i++){
    if(N[i] < min){
      min = N[i];
      min_pos = i;
    }
  }
  return min_pos;
}

int main(){
  scanf("%260s", N);
  scanf("%d", &k);

  const int length = strlen(N);
  const int need_pr = length - k;
  int already_pr = 0;
  int already_del = 0;

  int current_left = 0;
  int last_left = 0;
  bool is_first = true;
  bool have_output = false;

  while(already_pr < need_pr){
    current_left = find_min(last_left, last_left + (k - already_del) + 1);
    already_del += (current_left - last_left);
    const char& elem = N[current_left];
    if(elem == '0' && is_first){
      already_del++;
    } else {
      have_output = true;
      printf("%c", elem);
      already_pr++;
      is_first = false;
    }
    last_left = current_left + 1;
  }
  if(!have_output){
    printf("0");

  }




  return 0;
}
