#include <stdio.h>

void f (int n){
    printf("%d", n%10);
    if(n>=10){
        f(n/10);
    }
}

void f2 (int n){
    if(n>=10){
        f2(n/10);
    }
    printf("%d", n%10);
}

void binario (int n){
    if(n>=2){
        binario(n/2);
    }
    printf("%d",n%2);
}

void octal (int n){
    if(n>=8){
        octal(n/8);
    }
    printf("%d",n%8);
}

void hexa (int n){
    if(n>=16){
        hexa(n/16);
    }
    if(n%16==10){
        printf("A");
    }
    else if(n%16==11){
        printf("B");
    }
    else if(n%16==12){
        printf("C");
    }
    else if(n%16==13){
        printf("D");
    }
    else if(n%16==14){
        printf("E");
    }
    else if(n%16==15){
        printf("F");
    }
    else{
        printf("%d",n%16);
    }
}

int fatorial(int n){
  if(n == 1){
    return 1;
  }
  if(n>1){
    return n*fatorial(n-1);
  }
}

int main(){
    f(123);
    printf("\n");
    f2(123);
    printf("\n");
    binario(10);
    printf("\n");
    octal(123);
    printf("\n");
    hexa(123);
}
