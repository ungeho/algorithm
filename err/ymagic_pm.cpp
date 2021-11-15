#include <iostream>
#include <cmath>
#include "ymagic_pm.hpp"


int main(void) {
  double x,a;
  double tmp;

  std::cout << "Input x :"; std::cin >> x;
  a = magic(x);

  //バージョン　g++ (MinGW.org GCC-6.3.0-1) 6.3.0
  std::cout << "x + a - a = " << (x + a) - a << "\n";
  //加算による丸めの影響を確定させるために一時変数に格納
  tmp = x + a;
  std::cout << "x + a - a = " << tmp - a << "\n";
  tmp = x - a;
  std::cout << "x - a + a = " << tmp + a << "\n";


  return 0;
}
