#include <iostream>
#include <cassert>

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define SWAP(a,b)           {if(a != b){b = a - b; a -= b; b += a;}}


//クイックソート（昇順）計算量O(nlogn) 安定でない（同等のデータのソート前の順序が保たれない）
//特徴：大きなデータを扱う際にはかなり早いが配列の分割が大きく偏った場合、最悪計算量O(n^2)に落ちる。
void quick_sort(int *array,int first,int last) {
  int i=first;
  int j=last;
  int x=array[(first+last)/2];

  while(1) {
    while(array[i] < x) i++;
    while(x < array[j]) j--;
    if(i >= j ) break;
    SWAP(array[i],array[j]);
    i++; j--;
  }
  if(first < i -1) quick_sort(array, first, i - 1);
  if(j + 1 < last) quick_sort(array, j + 1, last);
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
  quick_sort(array,0,ARRAY_LENGTH(array)-1);
  for(int i = 1; i <= 10; i++) assert(array[i-1] == i);
  cout_array(array,ARRAY_LENGTH(array));

  return 0;
}
