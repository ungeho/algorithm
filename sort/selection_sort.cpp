#include <iostream>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int swap(int *a,int *b) {
  int *tmp= a;
  a = b;
  b = tmp;
}

//選択ソート(昇順)
void selection_sort(int *array,size_t size) {
  for( size_t i = 0; i < size - 1; ++i ){
    size_t min_idx = i;
    for( size_t j = i + 1; j < size; ++j ){
      //i番目にふさわしい値（昇順なので最も小さい値）を探す
      if( array[min_idx] > array[j] ){
        min_idx = j;
      }
    }
    swap(array[i], array[min_idx]);
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
  selection_sort(array,ARRAY_LENGTH(array));
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
