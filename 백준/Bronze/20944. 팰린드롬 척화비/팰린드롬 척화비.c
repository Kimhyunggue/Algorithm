#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  if(N%2==0){
    for(int i=0;i<N;i++){
      printf("a");
    }
  }
  else{
    for(int i=0;i<N/2;i++){
      printf("a");
    }
    printf("b");
    for(int i=0;i<N/2;i++){
      printf("a");
    }
  }

  return 0;
}