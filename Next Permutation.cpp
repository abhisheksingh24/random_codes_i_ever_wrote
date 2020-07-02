#include<iostream>
#include<algorithm>

using namespace std;

void swp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMin(int ar[], int beg, int size){
    int m = 1001, ind;
    for(int i = beg; i < size; i++){
        if(ar[i] > ar[beg-1] && ar[i] < m){
            m = ar[i];
            ind = i;
        }
    }
    if(m == 1001) return -1;
    return(ind);
}

int main(){
    bool flag;
    int n, k, perm[1000], ind;
    cin >> n >> k;
    while(k--){
        for(int i = 0; i < n; i++){
            cin >> perm[i];
        }
        bool found = false;
        for(int i = n-2; i>=0; i--){
            ind = findMin(perm, i+1, n);
            if(ind!=-1){
                swp(perm+i, perm+ind);
                sort(perm+i+1, perm+n);
                found = true;
                break;
            }
        }
        if(!found) for(int i =1; i <= n; i++) cout << i << " ";
        else for(int i = 0; i < n; i++) cout << perm[i] << " ";
        cout << endl;
    }
}
