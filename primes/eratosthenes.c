#include <stdio.h>
#include <math.h>

// nまでの素数を求める
// iが2以上の時、最小のiを残してiの倍数を全て消していく
// nまでの素数を求めたい時、2 <= i <=sqrt(i) の範囲で行う
void sieveoferatosthenes(int *flag,int n) {
  //2のみ特別扱いで初期化段階で2の倍数を消す
  flag[0] = 0; flag[1] = 0;
  for(int i = 2; i < n; i++) {
    flag[i] = i%2;
  }

  double sqrtn;
  sqrtn = sqrt((double)n);
  for(int i = 3; i < sqrtn; i+=2) {
    if (flag[i] == 0) continue;
    for(int j = i + 2; j < n; j+=2) {
      if(j%i == 0) flag[j] = 0;
    }
  }
}
void print_primes(int *flag,int n) {
  for(int i = 0,count=1; i < n; i++) if(flag[i]) printf("%2d:%5d\n",count++,i);
}

int main(void) {
  int n=100;
  int flag[n];

  sieveoferatosthenes(flag,n);

  print_primes(flag,n);

  return 0;
}
