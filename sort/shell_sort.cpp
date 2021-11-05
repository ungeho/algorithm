#include <iostream>
#include <cassert>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))


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

void cout_array(const int *array,size_t size) {
  for( size_t i = 0; i < size; i++) {
    cout << array[i];
    if(i < (size-1)) cout << ',';
  }
  cout << '\n';
}

int main(void) {
  int array[] = {5,1,4,2,7,10,6,8,9,3};
  cout_array(array,ARRAY_LENGTH(array));
  shell_sort(array,ARRAY_LENGTH(array));
  for(int i = 1; i <= 10; i++) assert(array[i-1] == i);
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
