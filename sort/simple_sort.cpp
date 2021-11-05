#include <iostream>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int swap(int *a,int *b) {
  int *tmp = a;
  a = b;
  b = tmp;
}


//単純ソート
void simple_sort(int *array,size_t size) {
  for( size_t i = 0; i < size - 1; ++i ){
    for( size_t j = i + 1; j < size; ++j ){
      if( array[i] > array[j] ){ //昇順に整列
        swap(array[i], array[j]);
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
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
