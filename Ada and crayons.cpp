#include<iostream>

using namespace std;

int steps(char cr[]){
    if(cr[0]=='\n') return 0;
    int flip1=0, flip2=0, i = 1;
    while(cr[i]!='\0'){
        if(cr[i]!=cr[i-1]){
            if(cr[i-1]=='U') flip1++;
            else flip2++;
        }
        i++;
    }
    if(cr[i-1]=='U') flip1++;
    else flip2++;
    return(min(flip1, flip2));
}

int main(){
    int t;
    char cr[51];
    cin >> t;
    while(t--){
        cin >> cr;
        cout << steps(cr) << endl;
    }
}
