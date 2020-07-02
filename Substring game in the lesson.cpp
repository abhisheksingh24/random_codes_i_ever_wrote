#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    char small = s[0];
    for(char c: s){
        if(small < c) cout << "Ann" << endl;
        else{
            cout << "Mike" << endl;
            small = c;
        }
    }
    cout <<
}