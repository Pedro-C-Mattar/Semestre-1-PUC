#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int R(int n){
  if(n == 0){
    return 1;
  }
  if(n > 0){
    return 2 * R(n - 1);
  }
}

int main(){
    int num = 0;
    int result = 0;
    scanf("%d", &num);
    result = R(num);
    printf("%d", result);
}
