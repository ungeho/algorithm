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

void calendar(int year) {
  int  month_date[12]    = {31, 28 + LeepYearFlag(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char month_name[12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

  for (int month = 1; month <= 12; month++) {
    int count = ZellersCongruence(year,month,1);
    printf("%s\n",month_name[month-1]);
    printf("  Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
    if(ZellersCongruence(year,month,1)) printf("     ");
    for (int i = 1; i < ZellersCongruence(year,month,1); i++)  printf("      ");

    for (int day = 1; day <= month_date[month-1]; day++) {
      if (count%7 == 0) {
        printf("%5d",day);
      } else {
        printf("%6d",day);
      }
      count++;
      if (count%7 == 0)  printf("\n");
    }
    if (count%7 != 0)  printf("\n");
  }
}

int main(void) {
  int year;

  printf("Please input the year:");
  scanf("%d",&year);
  calendar(year);

  return 0;
}
