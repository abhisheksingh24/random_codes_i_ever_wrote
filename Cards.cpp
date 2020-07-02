#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int z = 0, o = 0; 
    for(char c: s){
        if(c == 'z') z++;
        else if(c == 'n') o++;
    }
    while(o--) cout << 1 << " ";
    while(z--) cout << 0 << " ";
    cout << endl;
}