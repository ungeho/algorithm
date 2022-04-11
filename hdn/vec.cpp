#include <iostream>
#include <cmath>
#include <vector>


int main(void) {
  std::vector<int> v(3,0); //1次元 3は要素数 0は初期化する値
  std::cout << v.size() << std::endl;
  for (int i = 0; i < 3; i++) std::cout << v[i] << " ";
  std::cout << std::endl;
  v.resize(10);
  std::cout << v.size() << std::endl;
  for (int i = 0; i < 10; i++) v[i] = i;
  for (int i = 0; i < 10; i++) std::cout << v[i] << " ";
  std::cout << std::endl;

  std::vector<std::vector<int>> vv(4,std::vector<int>(3,0)); //2次元
  std::cout << vv.size() << "x" << vv[0].size() << std::endl;
  //nxnにサイズ変更
  int n = 2;
  vv.resize(n);
  for(int i = 0; i < n; i++) vv[i].resize(n);
  std::cout << vv.size() << "x" << vv[0].size() << std::endl;

  vv[0][1] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << vv[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::vector<std::vector<int>> tmp(2,std::vector<int>(2,0)); //2次元
  tmp = vv;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << tmp[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  n = 4;
  vv.resize(n);
  for(int i = 0; i < n; i++) vv[i].resize(n);

  for(int i = 0; i < n/2; i++) {
    for(int j = 0; j < n/2; j++) {
      vv[i][j] = tmp[i][j];
    }
  }
  for(int i = 0; i < n/2; i++) {
    for(int j = n/2; j < n; j++) {
      if(i==(j-n/2)) vv[i][j] = 1;
    }
  }
  for(int i = n/2; i < n; i++) {
    for(int j = n/2; j < n; j++) {
      vv[i][j] = tmp[i-n/2][j-n/2];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << vv[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  std::vector<std::vector<int>> e(2,std::vector<int>(2,0)); //2次元
  for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) if(i==j) e[i][j] = 1;
  std::vector<std::vector<int>> ep(2,std::vector<int>(2,0)); //2次元
  ep[0][1] = 1;


  std::vector<std::vector<std::vector<int>>> vvv(1, std::vector<std::vector<int>>(2, std::vector<int>(2,0))); //三次元
  n = 2;
  int n2 = pow(2,n);


  vvv.resize(n);
  for(int i = 0; i < n; i++) vvv[i].resize(n2);
  for(int i = 0; i < n; i++) for(int j = 0; j < n2; j++) vvv[i][j].resize(n2);

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      std::cout << vvv[1][i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  std::cout << "aaa" <<std::endl;

  for(int i = 0; i < n2; i++) {
    if(i < n2/2) {
      for(int j = 0; j < n2/2; j++) {
        vvv[0][i][j] = ep[i][j];
      }
    } else {
      for(int j = n2/2; j < n2; j++) {
        vvv[0][i][j] = ep[i-n2/2][j-n2/2];
      }
    }
  }


  for(int i = 0; i < n2/2; i++) {
    for(int j = n2/2; j < n2; j++) {
      if(i==(j-n2/2)) vvv[1][i][j] = 1;
    }
  }

  for(int i = 0; i < n2; i++) {
    for(int j = 0; j < n2; j++) {
      std::cout << vvv[0][i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for(int i = 0; i < n2; i++) {
    for(int j = 0; j < n2; j++) {
      std::cout << vvv[1][i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;



  return 0;
}
