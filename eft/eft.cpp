#include <iostream>
#include <cmath>
#include <iomanip>

//a+bの計算結果が x に入る。 a+b の演算時に発生した誤差が y に入る。
//近い数同士の引き算　|b|<=|a|<=2|b| であれば a-b の計算に誤差は入らないらしい
//また、実数->浮動小数点数　の変換で誤差が発生している事に注意
void twosum(double a,double b,double *x,double *y) {
  double tmp;
  *x  = a + b;
  tmp = *x - a;
  *y  = (a - (*x - tmp)) + (b - tmp); //a+bによる誤差を取得
}

void split(double a,double *x,double *y) {
  double tmp;
  tmp = a * (pow(2.0,27) + 1.0);
  *x   = tmp - (tmp - a);
  *y   = a - *x;
}

//a*bの計算結果が x に入る。 a*b の演算時に発生した誤差が y に入る。
void twoproduct(double a,double b,double *x,double *y) {
  double a1,a2,b1,b2;
  *x = a * b;
  split(a,&a1,&a2);
  split(b,&b1,&b2);
  *y = a2 * b2 - (((*x - a1 * b1) - a2 * b1) - a1 *b2);
}

inline void cout_result(double a,double b,double x,double y,char op) {
  std::cout << std::setprecision(17) << "a     = " << a << "\n";
  std::cout << std::setprecision(17) << "b     = " << b << "\n";
  std::cout << std::setprecision(17) << "a "<< op <<" b = " << x << "\n";
  std::cout << std::setprecision(17) << "err   = " << y << "\n";
}

int main(void) {
  double a,b,x,y;

  a = 0.1;
  b = 0.2;

  twosum(a,b,&x,&y);

  cout_result(a,b,x,y,'+');

  std::cout << "\n";

  twoproduct(a,b,&x,&y);

  cout_result(a,b,x,y,'*');


  return 0;
}
