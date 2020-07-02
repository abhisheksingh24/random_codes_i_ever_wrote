#include<stdio.h>

int sum(int a, int b){
    int c,d;
    return(a+b);
}

void main(){
    int (*f)();
    f = sum;
    printf("%p\n", f);
    printf("%d", (*f)(1,5));
}
