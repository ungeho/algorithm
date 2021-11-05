#include <iostream>
#include <cassert>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))


//挿入ソート（昇順） 計算量O(n^2) 安定（同等のデータのソート前の順序が保たれる） 特徴：事前にある程度ソート済みである場合、特に速い
void insertion_sort(int *array,size_t size) {
  for( size_t i = 1; i < size; i++) {
    int tmp = array[i];
    //挿入が必要かの確認
    if(array[i-1] > tmp) {
      size_t j = i;
      //後ろにずらして挿入場所を空ける
      do {
        array[j] = array[j-1];
        j--;
      } while (j > 0 && array[j-1] > tmp);
      array[j] = tmp;
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
  insertion_sort(array,ARRAY_LENGTH(array));
  for(int i = 1; i <= 10; i++) assert(array[i-1] == i);
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
