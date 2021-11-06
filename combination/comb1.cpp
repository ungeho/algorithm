#include <iostream>

//再帰で二つも呼び出してる為、計算量が膨大
//nCr = n-1Cr-1 + n-1Cr
unsigned long comb(int n,int r) {
  //nC0 = nCn = 1
  if(r == 0 || r == n) return 1;
  return comb(n-1,r-1) + comb(n-1,r);
}


int main(void) {
  std::cout << comb(45,10);
  return 0;
}
