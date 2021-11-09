#include <iostream>

//計算過程も整数
//nCr = (n-r+1)*...*(n-1)*n / ( 1*2*....*r*(r-1) )
unsigned long comb(int n,int r) {
  if(n < 0 || r < 0 || n < r) return 0; //error
  //nC0 = nCn = 1
  if(n == r || r == 0) return 1;
  // nCr = n!/(n-1)! = n
  // if(r == 1)           return n;
  if (r > n-r) r = n-r;
  unsigned long res = 1;
  for(int i = 1; i <= r; i++) {
    res *= n - r + i; // r * (n-r+i) (n-r+i = n-r+1,...,n)
    res /= i;
  }
  return res;
}


int main(void) {
  //i=9の時にオーバーフローして正しい値が出力されない
  // std::cout << comb(45,10);

  std::cout << comb(45,8);

  return 0;
}
