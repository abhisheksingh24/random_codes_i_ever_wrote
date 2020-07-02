#include<bits/stdc++.h>

using namespace std;

bool allZero(string s){
    for(int i = 1; i < s.size(); i++) if(s[i] == '1') return false;
    return true;
}

int main(){
    string s;
    cin >> s;
    if(s.size() % 2  == 0){
        cout << s.size() / 2 << endl;
        return 0;
    }
    if(!allZero(s)) cout << (s.size() + 1) / 2 << endl;
    else cout << (s.size() + 1) / 2 - 1 << endl;
    
}