#include<cstdio>
#include<iostream>
#include<algorithm>
struct Heap{
  double value;
  double amount;
  Heap(double v=0, double a=0): value(v), amount(a){};
  bool operator<(const Heap& rhs) const {
    return this->value > rhs.value;
  }
};

std::ostream& operator<<(std::ostream& os, const Heap& heap){
  os << '(' << heap.value << ',' << heap.amount << ") ";
  return os;
}

Heap ali(0,0);
Heap *tre;
int N, T;

int main(){
  std::cin >> N >> T;
  tre = new Heap[N];
  for(int i = 0; i < N; i++){
    double amount,value;
    std::cin >> amount >> value;
    tre[i].amount = amount;
    tre[i].value = value / amount;
  }
  std::sort(tre,tre+N);

  for(int i = 0; i < N && T-ali.amount > 0; i++){
    if(tre[i].amount <= 0) continue;
    if(T - ali.amount > tre[i].amount){
      ali.amount += tre[i].amount;
      ali.value += tre[i].value * tre[i].amount;
      tre[i].amount = 0;
    }else{
      double remain = T - ali.amount;
      ali.amount += remain;
      ali.value+= tre[i].value * remain;
      tre[i].amount -= remain;
    }
  }
  printf("%.2lf", ali.value);

  delete[] tre;
  return 0;
  
}
