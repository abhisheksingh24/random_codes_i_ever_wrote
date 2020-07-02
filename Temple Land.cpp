#include<iostream>

using namespace std;

bool height(int h[], int beg, int end, int step){
    for(int i = beg; i < end-1; i++){
        if(h[i+1] - h[i] != step) return false;
    }
    return true;
}

bool isValid(int h[], int n){
    int m = (n%2 ? n/2 : 0);
    return(m && h[0]==1 && height(h, 0, m, 1) && height(h, m, n-1, -1));
}

int main(){
    int s, n, h[100];
    cin >> s;
    for(; s; s--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        cout << (isValid(h, n) ? "yes\n" : "no\n");
    }
}
