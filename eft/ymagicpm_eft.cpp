#include <iostream>
#include <cmath>
#include <iomanip>


//a+bの計算結果が x に入る。 a+b の演算時に発生した誤差が y に入る。
//近い数同士の引き算　|b|<=|a|<=2|b| であれば a-b の計算に誤差は入らないらしい
//また、実数->浮動小数点数　の変換で誤差が発生している事に注意
void twosum(double a,double b,double *x,double *err) {
  double tmp;
  *x     = a + b;
  tmp    = *x - a;
  *err  += (a - (*x - tmp)) + (b - tmp); //a+bによる誤差を取得
}

int main(void) {
  double a,b,x,err;
  double tmp;

  std::cout << "Input a :"; std::cin >> a;

  //xの最上位bit
  int n = floor(log2(fabs(a)));
  b = pow( 2.0 , n + 53 ); //丸めの影響を最大にする為、有効桁数分左にずらす

  err = 0;
  twosum(a, b,&x,&err); //x = a + b
  twosum(x,-b,&x,&err); //x = (a + b) - b
  std::cout << "(a + b) - b = " << x   << "\t" << "err = " << err << "\n";

  err = 0;
  twosum(a,-b,&x,&err); //x = a - b
  twosum(x, b,&x,&err); //x = (a - b) + b
  std::cout << "(a - b) + b = " << x   << "\t" << "err = " << err << "\n";

  return 0;
}
