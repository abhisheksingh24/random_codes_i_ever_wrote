#include<iostream>

using namespace std;

bool isValid(char s[], int l){
    bool h = false;
    for(int i = 0; i < l; i++){
        if(h){
            if(s[i]=='H') return false;
            else if(s[i]=='T') h = false;
        }
        else{
            if(s[i]=='T')return false;
            else if(s[i]=='H') h = true;
        }
    }
    return(not h);
}

int main(){
    char snakes[500];
    int r, l;
    cin >> r;
    for(; r; r--){
        cin >> l;
        if(l) cin >> snakes;
        cout << (isValid(snakes, l) ? "Valid\n" : "Invalid\n");
    }
}
