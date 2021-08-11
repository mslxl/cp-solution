#include "cmath"
using namespace std;

class DigPow{
public:
  static int digPow(int n, int p){
    int raw = n;
    int value = 0;
    int t = 0;
    while(n > 0){
      t *= 10;
      t += n % 10;
      n /= 10;
    }
    while(t > 0){
      value += pow(t%10,p);
      p++;
      t/=10;
    }
    if (value % raw == 0){
      return value / raw;
    }else{
      return -1;
    }
  }
};
