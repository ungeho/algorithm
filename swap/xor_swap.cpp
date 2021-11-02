#include <iostream>

//inline関数    呼び出し側にコードが展開されるので関数呼び出しに伴うオーバーヘッド削減、特に内容が小さく頻繁に呼ばれる場合に有用
//テンプレート   広範囲の型に適用できるようにする
template<typename T>
inline void swap(T *a,T *b) {
  *b ^= *a; //B XOR A
  *a ^= *b; //A XOR (B XOR A) = (A XOR A) XOR B = B
  *b ^= *a; //(B XOR A) XOR B = (B XOR B) XOR A = A
}

template<typename T>
inline void show(T a,T b,char x,char y) {
  std::cout << x << "=" << a << "\t" << y << "=" << b << "\n";
}

int main(void) {
  int    a,b;
  double c,d;

  a = 1; b = 2;
  show(a,b,'a','b');
  swap(&a,&b);           //int型と判断
  show(a,b,'a','b');
  swap<int>(&a,&b);      //int型を指定
  show(a,b,'a','b');

  c = 0.5; d = 0.75;
  std::cout << "\n";
  show(c,d,'c','d');
  swap(&c,&d);          //double型と判断
  show(c,d,'c','d');
  swap<double>(&c,&d);  //double型を指定
  show(c,d,'c','d');




  return 0;
}
