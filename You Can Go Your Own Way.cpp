#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n;
    string p;
    cin >> t;
    for(int z = 1; z <= t; ++z){
        cin >> n;
        cin >> p;
        string q;
        for(char c: p){
            if(c == 'E') q += "S";
            else q += "E";
        }
        cout << "Case #" << z << ": " << q << endl;
    }
}