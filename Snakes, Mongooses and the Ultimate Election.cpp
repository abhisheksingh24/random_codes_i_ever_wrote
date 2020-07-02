#include<iostream>

using namespace std;

bool left(char a[], bool flag[], int i){
    return(i>0 && a[i-1]=='s' && flag[i-1]);
}

bool right(char a[], bool flag[], int i){
    return(a[i+1]!='\0' && a[i+1]=='s' && flag[i+1]);
}

int result(char a[]){
    bool flag[100];
    int snakes=0, mon=0;
    for(int i = 0; i < 100; i++) flag[i] = true;
    for(int i = 0; a[i] != '\0'; i++){
        if(a[i] == 's') snakes++;
        else{
            mon++;
            if(flag[i]){
                if(left(a, flag, i)){
                    snakes--;
                    flag[i-1] = false;
                    flag[i] = false;
                }
                else if(right(a, flag, i)){
                    snakes--;
                    flag[i+1] = false;
                    flag[i] = false;
                }
            }
        }

    }
    return(snakes - mon);
}

int main(){
    int t;
    char a[101];
    cin >> t;
    for(; t; t--){
        cin >> a;
        if(result(a) > 0) cout << "snakes\n";
        else if(result(a) < 0) cout << "mongooses\n";
        else cout << "tie\n";

    }
}
