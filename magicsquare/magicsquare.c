#include<stdio.h>


//[N * 2 + 1][N * 2 + 1]の魔法陣を生成
#define N 4


void generate_magicsquare(int size,int a[size][size]) {
  int k = 0;

  for(int i = -size/2; i <= size/2; i++) {
    for(int j = 0; j < size; j++) {
      a[(j-i+size)%size][(j+i+size)%size] = ++k;
    }
  }
}

void print_magicsquare(int size,int a[size][size]) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      printf("%4d",a[i][j]);
    }
    printf("\n");
  }
}


int main(void) {
  int a[N * 2 + 1][N * 2 + 1];
  int size = N * 2 + 1;

  generate_magicsquare(size,a);
  print_magicsquare(size,a);

  return 0;
}
