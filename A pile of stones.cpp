#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int st = 0, mn = 0;
    for(char c: s){
        if(c == '-') st--;
        else if(c == '+') st++;
        if(st < mn) mn = st;
    }
    cout << max(0, st - mn) << endl;
}