#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0, b = 0;
    vector<int> color(n);
    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            if(r >= b) color[i] = 0, r--;
            else color[i] = 1, b--;
        }
        else{
            if(r <= b) color[i] = 0, r++;
            else color[i] = 1, b++;
        }
    }
    for(int c: color) cout << c;
    cout << endl;
}