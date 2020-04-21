unsigned int countBits(unsigned long long n){
  unsigned int v = 0;
  while(n > 0){
    v += n % 2;
    n /= 2;
  }
  return v;
}
