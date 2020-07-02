#include<iostream>

using namespace std;

/*
int vFlag(char a[], char b[], int n){
    for(int i = 0; i < n; i++){
        if(a[i]=='*' && b[i]=='*'){
            return 1;
        }
    }
    return 0;
}
*/


int fences(char a[], char b[], int n){
    bool fen[2] = {true,true}, vF = false;
    int f = 0;
    for(int i = 0; i < n; i++){
        if(a[i]=='*'){
            if(b[i] == '*' || fen[1] == false) vF = true;
            if(fen[0]) fen[0] = false;
            else{
                f++;
                if(b[i]=='*')fen[1] = false;
                else fen[1] = true;
            }
        }
        else if(b[i]=='*'){
            if(a[i]=='*' || fen[0] == false) vF = true;
            if(fen[1]) fen[1] = false;
            else{
                f++;
                if(a[i]=='*') fen[0] = false;
                else fen[0] = true;
            }
        }
    }
    if(vF) f++;
    return(f);
}

int main(){
    int t, n;
    char a[100001], b[100001];
    cin >> t;
    for(; t; t--){
        cin >> n;
        cin >> a;
        cin >> b;
        cout << fences(a, b, n) << endl;
    }
}
