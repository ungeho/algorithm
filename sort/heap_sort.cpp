#include <iostream>
#include <cassert>

using namespace std;

#define THRESHOLD 10
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define SWAP(a,b)           {if(a != b){b = a - b; a -= b; b += a;}}

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



//ヒープソート（昇順）計算量O(nlogn) 安定でない（同等のデータのソート前の順序が保たれない） 特徴：最悪の場合でも計算量O(nlogn)であり、スタックが不要
void heap_sort(int *array,size_t size) {
  int i,j,k;
  int x;

  for(k = size / 2; k >= 1; k--) {
    i = k; x = array[i];
    while((j = 2 * i) <= size)  {
      if(j < size && array[j] < array[j + 1]) j++;
      if(x >= array[j]) break;
      array[i] = array[j]; i=j;
    }
    array[i] = x;
  }
  while(size > 1) {
    x = array[size]; array[size] = array[1]; size--;
    i = 1;
    while ( (j = 2 * i) <= size ) {
      if(j < size && array[j] < array[j + 1]) j++;
      if(x >= array[j]) break;
      array[i] = array[j]; i=j;
    }
    array[i] = x;
  }

  insertion_sort(array,size);
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
  heap_sort(array,ARRAY_LENGTH(array));
  // for(int i = 1; i <= 10; i++) assert(array[i-1] == i);
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
