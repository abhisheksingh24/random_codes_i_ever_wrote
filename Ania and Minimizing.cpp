#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n>> k;
    string s;
    cin >> s;
    if(n == 1 && k > 0) s[0] = '0', k = 0; 
    if(k > 0 && s[0] != '1') s[0] = '1', k--;
    for(int i = 1; i < n && k > 0; i++){
        if(s[i] != '0') s[i] = '0', k--;
    }
    cout << s << endl;
}