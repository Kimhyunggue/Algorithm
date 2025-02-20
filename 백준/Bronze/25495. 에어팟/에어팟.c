#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
  int N, a1, a2 = 0, batt = 1, cnt = 0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&a1);
    if(i==0){
      cnt += 2;
    }
    else if (a1 == a2){
      if (i==1) {
        batt = 2;
      }
      batt *= 2;
      cnt += batt;
      if (cnt >= 100) {
        batt = 1;
        cnt = 0;
      }
    }
    else {
      batt = 2;
      cnt += batt;
      if (cnt >= 100) {
        batt = 1;
        cnt = 0;
      }
    }
    a2 = a1;
  }

  printf("%d", cnt);

  return 0;
}