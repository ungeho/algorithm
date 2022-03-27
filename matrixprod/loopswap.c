/*
ループ交換法：ループの順番を入れ替える事でメモリのアクセス方向を連続にしている。
※C言語では行方向に連続しているが、言語によって違う場合があるらしいので注意。
コンパイル : gcc -O3 matrixprod.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// 行列サイズ N*N
#define N 256

void initMatrix(int mat[N][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      mat[i][j] = 0;
    }
  }
}

void randMatrix(int mat[N][N]) {
  srand((unsigned int)time(NULL));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      mat[i][j] = rand() % 10;
    }
  }
}

void showMatrix(int mat[N][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      printf("[%d]",mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void prodMatrix(int matRes[N][N],int matLeft[N][N],int matRight[N][N]) {
  initMatrix(matRes);
  for(int i = 0; i < N; i++) {
    for(int k = 0; k < N; k++) {
      int tmp = 0;
      for(int j = 0; j < N; j++) {
        matRes[i][j] += matLeft[i][k] * matRight[k][j];
      }
    }
  }
}


int main(void) {
  clock_t start,end;
  int a[N][N],b[N][N],c[N][N];


  randMatrix(a);
  sleep(1);
  randMatrix(b);

  // showMatrix(a);
  // showMatrix(b);

  start = clock();
  prodMatrix(c,a,b);
  end = clock();
  // showMatrix(c);

  const double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
  printf("calc time : %lf[ms]\n", time);

  return 0;
}
