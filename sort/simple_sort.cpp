#include <iostream>
#include <cassert>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define SWAP(a,b)           {if(a != b){b = a - b; a -= b; b += a;}}


//単純ソート（昇順）計算量O(n^2) 安定でない（同等のデータのソート前の順序が保たれない）
void simple_sort(int *array,size_t size) {
  for( size_t i = 0; i < size - 1; i++ ){
    for( size_t j = i+1; j < size; j++ ){
      if( array[i] > array[j] ){
        SWAP(array[i], array[j]);
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
  simple_sort(array,ARRAY_LENGTH(array));
  for(int i = 1; i <= 10; i++) assert(array[i-1] == i);
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
