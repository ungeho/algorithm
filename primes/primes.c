#include <stdio.h>

//n個の素数を生成
void generate_primes(int *prime,int n) {
  int odd = 1;

  prime[0] = 2;
  for (int i = 1; i < n;) {
    int j = 0;
    odd += 2;
    //奇数を既に見つかった素数で割ったあまりが0以外になる値を探す
    while(j < i && odd%prime[j]) j++;
    if(j == i) prime[i++] = odd;
  }
}

//n個の素数を生成
void print_primes(int *prime,int n) {
  for(int i = 0; i < n; i ++) printf("%2d:%5d\n",i+1,prime[i]);
}

int main(void) {
  int n = 25;
  int prime[n];
  generate_primes(prime,n);
  print_primes(prime,n);

  return 0;
}
