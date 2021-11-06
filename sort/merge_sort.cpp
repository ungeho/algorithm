#include <iostream>
#include <cassert>

using namespace std;

#define THRESHOLD 10
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define SWAP(a,b)           {if(a != b){b = a - b; a -= b; b += a;}}



//マージソート（昇順）計算量O(nlogn) 安定（同等のデータのソート前の順序が保たれる） 特徴：クイックソートと違い、どんな入力に対しても高速
void merge_sort(int *array,int first,int last) {
  int middle;
  static int i,j,k,p;
  int work[(last+1)/2 + 1];

  if( first < last ) {
    middle = (first + last) / 2;
    merge_sort(array,first      , middle);
    merge_sort(array,middle + 1 ,   last);
    p = 0;
    for(i = first; i <= middle; i++) work[p++] = array[i];
    i = middle + 1; j = 0; k = first;
    while(i <= last && j < p) {
      if(work[j] <= array[i]) array[k++] = work[j++];
      else                    array[k++] = array[i++];
    }
    while (j < p) array[k++] = work[j++];
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
  merge_sort(array,0,ARRAY_LENGTH(array)-1);
  for(int i = 1; i <= 10; i++) assert(array[i-1] == i);
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
