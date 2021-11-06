#include <iostream>
#include <cmath>
#include <cassert>
#include <random>

using namespace std;

#define THRESHOLD 10
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define SWAP(a,b)           {if(a != b){b = a - b; a -= b; b += a;}}

//シェルソート（昇順）計算量O(n^1.25)~O(n^1.5) 安定でない（同等のデータのソート前の順序が保たれない）
void shell_sort(int *array,size_t size) {
  size_t h = 1;
  //hは挿入ソートを行う時の要素同士の間隔
  //h=h*3+1 で要素数/9を超えない最大の値を探す。 （1,4,13,40,121,...）
  for(size_t h_tmp = 1; h_tmp < size/9; h_tmp = h_tmp * 3 + 1) h = h_tmp;

  while(h > 0 ) {
    for( size_t i = h; i < size; i++) {
      int tmp = array[i];
      //挿入が必要かの確認（要素同士の間隔がhの挿入ソート）
      if(array[i-h] > tmp) {
        size_t j = i;
        //後ろにずらして挿入場所を空ける
        do {
          array[j] = array[j-h];
          j--;
        } while (j > 0 && array[j-h] > tmp);
        array[j] = tmp;
      }
    }
    h /= 3; //h=h*3+1に倣って間隔を狭めていく　h=1までにほぼ整列されている状態が理想
  }
}

//3要素の中央値
int median3(int x, int y, int z) {
  if( x < y ) {
    if( y < z ) {
      return y;
    } else if( z < x ) {
      return x;
    } else {
      return z;
    }
  } else {
    if( z < y ) {
      return y;
    } else if( x < z ) {
      return x;
    } else {
      return z;
    }
  }
}


//非再帰版クイックソート（昇順）計算量O(nlogn) 安定でない（同等のデータのソート前の順序が保たれない）
//特徴：大きなデータを扱う際にはかなり早いが配列の分割が大きく偏った場合、最悪計算量O(n^2)に落ちる。
void quick_sort(int *array,size_t size) {
  const size_t stack_size = (size_t)(log2((double)size)+1); //スタックサイズはlog2(n)以上で足りる
  int i,j;
  int left,right,p;
  int leftstack[stack_size],rightstack[stack_size];
  int x;
  left = 0; right = size - 1; p = 0;
  while(1) {
    if(right - left <= THRESHOLD) {
      if(p == 0) break;
      p--;
      left  = leftstack[p];
      right = rightstack[p];
    }
    //基準値の選択
    x = median3(array[left],array[(left+right+1)/2],array[right]);
    i = left; j = right;
    while(1) {
      while (array[i] < x       ) i++; //基準値以上の値が見つかるまで右に進む
      while (       x < array[j]) j--; //基準値以下の値が見つかるまで左に進む
      if(i >= j) break;                //ぶつかったらループ終了
      SWAP(array[i],array[j]);         //基準値の左右で組み分けを行う（基準値より左側の基準値以上の値と基準値より右側の基準値以下の値を交換）
      i++; j--;
    }
    //左右の配列の要素数を比較して、少ない方を先に処理
    if ( i - left > right - j) {
      if(i - left > THRESHOLD) {
        leftstack[p]  = left;
        rightstack[p] = i-1;
        p++;
      }
      left = j + 1;
    } else {
      if(right - j > THRESHOLD) {
        leftstack[p]  = j + 1;
        rightstack[p] = right;
        p++;
      }
      right = i - 1;
    }

  }
  shell_sort(array,size); //区間がある程度狭くなったらシェルソート
}

void cout_array(const int *array,size_t size) {
  for( size_t i = 0; i < size; i++) {
    cout << array[i];
    if(i < (size-1)) cout << ',';
  }
  cout << '\n';
}

void random_array(int *array,size_t size) {
  std::random_device rnd;
  for(size_t i = 0; i < size; i++) {
    array[i] = rnd()%1000;
  }
}

int main(void) {
  int array[100],array2[100];
  random_array(array,ARRAY_LENGTH(array));
  cout_array(array,ARRAY_LENGTH(array));
  quick_sort(array,ARRAY_LENGTH(array));
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
