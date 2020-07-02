#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(char c: s){
        if(c == '1') cnt++;
        else cnt--;
    }
    if(!cnt){
        char c = s[n - 1];
        s.pop_back();
        cout << 2 << endl;
        cout << s << " " << c << endl;
    }
    else{
        cout << 1 << endl;
        cout << s;
    }
}