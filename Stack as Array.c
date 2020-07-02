#include<stdio.h>

#define SIZE 100

struct stack{
    int ar[SIZE];
    int top;
};

struct stack s;

void push(){
    if(s.top == SIZE-1){
        printf("Overflow\n");
        return;
    }
    printf("Enter element : ");
    int n;
    scanf("%d", &n);
    s.top++;
    s.ar[s.top] = n;
    printf("Pushed Successfully\n");
}

int pop(){
    if(s.top == -1){
        printf("Underflow\n");
        return -1;
    }
    int res = s.ar[s.top];
    s.top--;
    return res;
}

void view(){
    if(s.top == -1){
        printf("Underflow\n");
        return;
    }
    int i;
    for(i = 0; i <= s.top; i++){
        printf("%d ", s.ar[i]);
    }
    printf("\n");
}

void main(){
    s.top = -1;
    int ch, popped;
    do{
        printf("Stack \n 1. Push \n 2. Pop \n 3. View \n 4. Exit\n");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            push();
            break;
        case 2:
            popped = pop();
            if(popped != -1) printf("Popped Value is %d\n", popped);
            break;
        case 3:
            view();
            break;
        }
    }while(ch!=4);
}
