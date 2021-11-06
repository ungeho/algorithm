#include<stdio.h>


//[N * 2 + 1][N * 2 + 1]の魔法陣を生成
#define N 4


int main(void) {
  int k = 0;
  int a[N * 2 + 1][N * 2 + 1];
  int size = N * 2 + 1;
  //初期化
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      a[i][j] = 0;
    }
  }

  //生成
  for(int i = -size/2; i <= size/2; i++) {
    for(int j = 0; j < size; j++) {
      a[(j-i+size)%size][(j+i+size)%size] = ++k;
    }
  }
  //表示
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      printf("%4d",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
