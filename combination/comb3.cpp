#include <iostream>

//非再帰
unsigned long comb(int n,int r) {
  if (r > n-r) r = n-r;
  //nC0 = nCn = 1
  if(n == r || r == 0) return 1;
  //nCr = n!/(n-1)! = n
  if(r == 1)           return n;
  if(n < 0 || r < 0 || n < r || r > 17) return 0; //error

  unsigned long array[17];

  for(int i = 1; i < r; i++) array[i] = i + 2;
  for(int i = 3; i <= n - r + 1; i++) {
    array[0] = i;
    for(int j = 1; j < r; j++) array[j] += array[j-1];
  }
  return array[r - 1];
}


int main(void) {
  std::cout << comb(45,10);
  return 0;
}
