#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
  long long int N,a;
  scanf("%lld",&N);
  scanf("%lld",&a);
  if(N>=6)
    printf("Love is open door");
  else if(a==1){
    for(int i=1;i<N;i++){
        if(i%2==1){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
  }
  else{
    for(int i=1;i<N;i++){
        if(i%2==1){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
  }

  return 0;
}
