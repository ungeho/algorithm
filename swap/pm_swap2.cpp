#include <iostream>
#include <cassert>

using namespace std;


//inline関数    呼び出し側にコードが展開されるので関数呼び出しに伴うオーバーヘッド削減、特に内容が小さく頻繁に呼ばれる場合に有用
//テンプレート   広範囲の型に適用できるようにする
template<typename T>
inline void swap(T *a,T *b) { //a==b　の場合、aもbも0になるので分岐が必要。
  if(*a != *b) {
    *b  = *a - *b;
    *a -= *b; //a-(a-b)=b
    *b += *a; //b+(a-b)=a
  }
}

template<typename T>
inline void show(T a,T b,char x,char y) {
  cout << x << "=" << a << "\t" << y << "=" << b << "\n";
}

int main(void) {
  int    a,b;
  double c,d;

  a = 1; b = 2;

  show(a,b,'a','b');

  swap(&a,&b);           //int型と判断
  assert(a == 2 && b == 1);
  show(a,b,'a','b');

  swap<int>(&a,&b);      //int型を指定
  assert(a == 1 && b == 2);
  show(a,b,'a','b');

  cout << "\n";

  c = 0.5; d = 0.75;

  show(c,d,'c','d');

  swap(&c,&d);          //double型と判断
  assert(c == 0.75 && d == 0.5);
  show(c,d,'c','d');

  swap<double>(&c,&d);  //double型を指定
  assert(c == 0.5 && d == 0.75);
  show(c,d,'c','d');

  return 0;
}
