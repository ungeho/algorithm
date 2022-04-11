#include <iostream>
#include <vector>
#include <cmath>



int main(void) {
  std::vector<std::vector<std::vector<int>>> vvv(1, std::vector<std::vector<int>>(2, std::vector<int>(2,0))); //三次元
  std::vector<std::vector<std::vector<int>>> tmp(1, std::vector<std::vector<int>>(2, std::vector<int>(2,0))); //三次元

  //HDNを生成して出力
  for(int n = 1; n <= 4; n++) {
    int n2 = pow(2, n);

    if(n > 1) {
      tmp.resize(n-1);
      for(int i = 0; i < n-1; i++) tmp[i].resize(n2/4);
      for(int i = 0; i < n-1; i++) tmp[i] = vvv[i];
    }

    vvv.resize(n);
    for(int i = 0; i < n; i++) vvv[i].resize(n2);
    for(int i = 0; i < n; i++) for(int j = 0; j < n2; j++) vvv[i][j].resize(n2);

    if(n == 1) vvv[0][0][1] = 1;



    if(n == 2) {
      for(int i = 0; i < n2/2; i++) {
        for(int j = 0; j < n2; j++) {
          if(j < n2/2) {
            vvv[0][i][j] = tmp[0][i][j];
          } else {
            if(i == (j-n2/2)) vvv[1][i][j] = 1;
          }
        }
      }
      for(int i = n2/2; i < n2; i++) {
        for(int j = n2/2; j < n2; j++) {
          vvv[0][i][j] = tmp[0][i-n2/2][j-n2/2];
        }
      }
    }


    if(n >= 3) {
      //初期化
      for(int k = 0; k < n; k++) {
        for(int i = 0; i < n2/2; i++) {
          for(int j = 0; j < n2/2; j++) {
            vvv[k][i][j] = 0;
          }
        }
      }

      //生成される行列の個数
      for(int k = 0; k < n; k++) {
        if(k < n-1) {
          for(int i = 0; i < n2/2; i++) {
            for(int j = 0; j < n2/2; j++) {
                vvv[k][i][j]            = tmp[k][i][j];
                vvv[k][i+n2/2][j+n2/2]  = tmp[k][i][j];
            }
          }
        } else {
          for(int i = 0; i < n2/2; i++) {
            for(int j = n2/2; j < n2; j++){
              if(i==j-n2/2) vvv[k][i][j] = 1;
            }
          }
        }
      }
    }



    std::cout << n << "-HDN" << std::endl << std::endl;
    for(int m = 0; m < n; m++) {
      for(int i = 0; i < n2; i++) {
        for(int j = 0; j < n2; j++) {
          std::cout << vvv[m][i][j] << " ";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
  }





  return 0;
}
