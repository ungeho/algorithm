#include <iostream>

//再帰で関数を二つ以上呼び出してる場合、一つに出来ると処理速度が大分良くなる
//n!  = n*(n-1)!
//nCr = n*(n-1)*(n-2)...(n-r+1)/r! = (n-1)*(n-2)...(n-r+1)/(r-1)! * n/r = n-1Cr-1 * n/r
unsigned long comb(int n,int r) {
  if (r > n-r) r = n-r;
  if(n < 0 || r < 0 || n < r) return 0; //error
  //nC0 = nCn = 1
  if(n == r || r == 0) return 1;
  //nCr = n!/(n-1)! = n
  if(r == 1)           return n;
  return comb(n - 1, r - 1) * (double)n / (double)r;
}


int main(void) {
  std::cout << comb(45,10);
  return 0;
}
