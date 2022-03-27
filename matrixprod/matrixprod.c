/*
通常の行列積
コンパイル : gcc -O3 matrixprod.c
計算時間   :約25ms
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
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
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
