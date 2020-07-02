#include<stdio.h>

struct seqList{
    int ar[100];
    int n;
};

void init(struct seqList *s){
    s -> n = 0; 
}

void insert(struct seqList *s, int val, int loc){
    loc -= 1;
    int n = (s -> n);
    if(loc > n){
        printf("Invalid index\n");
        return;
    }
    if(n >= 99){
        printf("Overflow\n");
        return;
    }
    int i;
    for(i = n; i > loc; i -= 1){
        s -> ar[i] = s -> ar[i-1];
    }
    s -> ar[loc] = val;
    s -> n = n + 1;
    printf("Inserted %d successfully\n", val);
}

void insertAtEnd(struct seqList *s, int val){
    insert(s, val, (s -> n) + 1);
}

void search(struct seqList s, int val){
    int i, n = s.n;
    for(i = 0; i < n; i += 1){
        if(s.ar[i] == val){
            printf("Element present at location : %d\n", i+1);
            return;
        }
    }
    printf("Element not found\n");
}

void delete(struct seqList *s, int ind){
    int i, n = s -> n;
    ind -= 1;
    printf("Deleted %d successfully\n", s -> ar[ind]);
    for(i = ind; i < n - 1; i += 1){
        s -> ar[i] = s-> ar[i + 1];
    }
    s -> n = n - 1;
}

void display(struct seqList s){
    for(int i = 0; i < (s.n); i += 1){
        printf("%d ", s.ar[i]);
    }
    printf("\n");
}

void get(struct seqList s, int ind){
    printf("Element at index %d = %d\n", ind, s.ar[ind - 1]);
}

void maximum(struct seqList s){
    int i, id = 0;
    for(i = 1; i < s.n; i += 1){
        if(s.ar[i] > s.ar[id]){
            id = i;
        }
    }
    printf("Maximum = %d\n", s.ar[id]);
}

void sort(struct seqList *s){
    int i, j;
    for(i = 0; i < s -> n; i+=1){
        int id = i;
        for(j = i + 1; j < s-> n; j += 1){
            if(s -> ar[j] < s -> ar[id]){
                id = j;
            }
        }
        int temp = s -> ar[i];
        s -> ar[i] = s -> ar[id];
        s -> ar[id] = temp;
    }
    printf("List is successfully sorted\n");
}

void insertAsc(struct seqList *s, int val){
    int i;
    for(i = 0; i < s -> n; i += 1){
        if(s -> ar[i] >= val){
            insert(s, val, i + 1);
            return;
        }
    }
    insertAtEnd(s, val);
}

void deleteMultiple(struct seqList *s, int ind, int cnt){
    int temp = cnt;
    while(temp > 0){
        delete(s, ind);
        temp -= 1;
    }
    printf("Deleted %d elements successfully\n", cnt);
}

void invert(struct seqList *s){
    int i = 0, j = (s -> n) - 1;
    for(; i < j; i += 1, j -= 1){
        int temp = s -> ar[i];
        s -> ar[i] = s -> ar[j];
        s -> ar[j] = temp; 
    }
    printf("List inverted successfully\n");
}

void main(){
    struct seqList lst;
    init(&lst);
    insertAtEnd(&lst, 21);
    insertAtEnd(&lst, 18);
    insertAtEnd(&lst, 30);
    insertAtEnd(&lst, 78);
    insertAtEnd(&lst, 42);
    insertAtEnd(&lst, 56);
    display(lst);
    get(lst, 3);
    insert(&lst, 67, 3);
    display(lst);
    delete(&lst, 6);
    display(lst);
    search(lst, 75);
    maximum(lst);
    sort(&lst);
    display(lst);
    insertAsc(&lst, 35);
    display(lst);
    deleteMultiple(&lst, 2, 3);
    display(lst);
    invert(&lst);
    display(lst);
}