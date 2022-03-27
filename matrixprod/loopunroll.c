/*
ループアンローリング：ループを展開することでforの分岐命令の回数を減らしている。
並列処理も使用(OpenMP、MPI)
NUMPROCSの値を環境に合わせて変更
windows10、MinGWでインストールしたものを使用
コンパイル : gcc -O3 -fopenmp loopunroll.c
計算時間　 :約2ms
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<omp.h>

// 行列サイズ N*N
#define N 256
//使用環境のプロセッサの数によって変更
#define NUMPROCS 12

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
  int ib = N/NUMPROCS; //NUMPROCSはprocessorの数
  int i,j,k;
  #pragma omp parallel for private(j,k)
  for(i = 0; i < ib; i+=4) {
    int i1 = i + 1;
    int i2 = i + 2;
    int i3 = i + 3;
    for(k = 0; k < N; k+=4) {
      int k1 = k + 1;
      int k2 = k + 2;
      int k3 = k + 3;
      for(j = 0; j < N; j++) {
        matRes[i][j]  += matLeft[i][k]   * matRight[k][j];
        matRes[i][j]  += matLeft[i][k1]  * matRight[k1][j];
        matRes[i][j]  += matLeft[i][k2]  * matRight[k2][j];
        matRes[i][j]  += matLeft[i][k3]  * matRight[k3][j];

        matRes[i1][j] += matLeft[i1][k]  * matRight[k][j];
        matRes[i1][j] += matLeft[i1][k1] * matRight[k1][j];
        matRes[i1][j] += matLeft[i1][k2] * matRight[k2][j];
        matRes[i1][j] += matLeft[i1][k3] * matRight[k3][j];

        matRes[i2][j] += matLeft[i2][k]  * matRight[k][j];
        matRes[i2][j] += matLeft[i2][k1] * matRight[k1][j];
        matRes[i2][j] += matLeft[i2][k2] * matRight[k2][j];
        matRes[i2][j] += matLeft[i2][k3] * matRight[k3][j];

        matRes[i3][j] += matLeft[i3][k]  * matRight[k][j];
        matRes[i3][j] += matLeft[i3][k1] * matRight[k1][j];
        matRes[i3][j] += matLeft[i3][k2] * matRight[k2][j];
        matRes[i3][j] += matLeft[i3][k3] * matRight[k3][j];
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
