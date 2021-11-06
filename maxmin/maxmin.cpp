#include <iostream>
#include <cassert>

#define MAX2(x,y) (x > y ? x : y )
#define MIN2(x,y) (x < y ? x : y )

int main(void) {
  int a,b,c;

  a = 3; b = 1; c = 5;

  assert(MAX2(a,b) == a);
  std::cout << MAX2(a,b)          << "\n";
  assert(MAX2(c,b) == c);
  std::cout << MAX2(c,b)          << "\n";
  assert(MAX2(a,MAX2(b,c)) == c);
  std::cout << MAX2(a,MAX2(b,c))  << "\n";

  assert(MIN2(a,b) == b);
  std::cout << MIN2(a,b)          << "\n";
  assert(MIN2(c,b) == b);
  std::cout << MIN2(c,b)          << "\n";
  assert(MIN2(a,MIN2(b,c)) == b);
  std::cout << MIN2(a,MIN2(b,c))  << "\n";
}
