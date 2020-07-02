#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, k, a, b, c;
    cin >> t;
    while(t--){
        cin >> k;
        cin >> a >> b >> c;
        bool win = false;
        if(a+b+c == k) win =true;
        if(a+b-c == k) win =true;
        if(a-b+c == k) win =true;
        if(a-b-c == k) win =true;
        if(-a+b+c == k) win =true;
        if(-a+b-c == k) win =true;
        if(-a-b+c == k) win =true;
        if(-a-b-c == k) win =true;
        if(win) cout << "WIN\n";
        else cout << "LOSE\n";
    }
}