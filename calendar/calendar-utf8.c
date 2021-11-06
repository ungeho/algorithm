#include <stdio.h>

int LeepYearFlag(int year) {
  if (year%400 == 0 || (year%4 == 0 && year%100 != 0) ) {
    return 1;
  } else {
    return 0;
  }
}

//ツェラーの公式
int ZellersCongruence(int year,int month,int day) {
  if(month < 3){
    year--;
    month+=12;
  }
  return (year + year/4 - year/100 + year/400 + (13 * month + 8)/5 + day)%7;
}

int main(void) {
  int year;

  printf("西暦で年を入力してください:");
  scanf("%d",&year);

  int month_date[12] = {31, 28 + LeepYearFlag(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int month = 1; month <= 12; month++) {
    int count = ZellersCongruence(year,month,1);
    printf("%d年%d月\n",year,month);
    printf("  日  月  火  水  木  金  土\n");
    for (int i = 0; i < ZellersCongruence(year,month,1); i++)  printf("    ");

    for (int day = 1; day <= month_date[month-1]; day++) {
      printf("%4d",day);
      count++;
      if (count%7 == 0)  printf("\n");
    }
    if (count%7 != 0)  printf("\n");
  }

  return 0;
}
