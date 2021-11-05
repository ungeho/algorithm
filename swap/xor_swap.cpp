#include <iostream>
#include <cassert>

using namespace std;


//ビット演算子は浮動小数点型に対応してない為、double型のswapに使おうとするとコンパイラに怒られる。
//また、A == B だった場合、AもBも0になる。
inline void swap(int *a,int *b) {
  if(*a != *b) {
    *b ^= *a; //B XOR A
    *a ^= *b; //A XOR (B XOR A) = (A XOR A) XOR B = B
    *b ^= *a; //(B XOR A) XOR B = (B XOR B) XOR A = A
  }
}

inline void show(int a,int b,char x,char y) {
  cout << x << "=" << a << "\t" << y << "=" << b << "\n";
}

int main(void) {
  int    a,b;

  a = 1; b = 2;
  show(a,b,'a','b');
  swap(&a,&b);
  assert(a == 2 && b == 1);
  show(a,b,'a','b');

  return 0;
}
