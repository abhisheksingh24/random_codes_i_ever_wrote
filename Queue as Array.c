#include<stdio.h>

#define SIZE 100

struct queue{
    int ar[SIZE];
    int front, rear;
};

struct queue s;

void enqueue(){
    if(s.rear == SIZE-1){
        printf("Overflow\n");
        return;
    }
    printf("Enter element : ");
    int n;
    scanf("%d", &n);
    s.rear++;
    s.ar[s.rear] = n;
    printf("Pushed Successfully\n");
}

int dequeue(){
    if(s.rear == s.front - 1){
        printf("Underflow\n");
        return -1;
    }
    int res = s.ar[s.front];
    s.front++;
    return res;
}

void view(){
    if(s.rear == s.front-1){
        printf("Underflow\n");
        return;
    }
    int i;
    for(i = s.front; i <= s.rear; i++){
        printf("%d ", s.ar[i]);
    }
    printf("\n");
}

void main(){
    s.front = 0; s.rear = -1;
    int ch, popped;
    do{
        printf("Queue \n 1. Enqueue \n 2. Dequeue \n 3. View \n 4. Exit\n");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            enqueue();
            break;
        case 2:
            popped = dequeue();
            if(popped != -1) printf("Popped Value is %d\n", popped);
            break;
        case 3:
            view();
            break;
        }
    }while(ch!=4);
}
