#include <iostream>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define SWAP(a,b)           {if(a != b){b = a - b; a -= b; b += a;}}


//バブルソート（昇順） 計算量O(n^2) 安定（同等のデータのソート前の順序が保たれる）
void bubble_sort(int *array,size_t size) {
  for( size_t i = 0; i < size - 1; ++i ){
    for( size_t j = 1; j < size - i; ++j ){ //末尾から確定
      if( array[j-1] > array[j] ){ //常に隣を比較して末尾に来る値を浮き上がらせる
        SWAP(array[j-1], array[j]); //昇順にする為に、末尾に一番大きい値を持っていく
      }
    }
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
  bubble_sort(array,ARRAY_LENGTH(array));
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
