#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string n;
    cin >> t;
    for(int z = 1; z <= t; ++z){
        cin >> n;
        string a, b;
        bool four = false;
        for(char c: n){
            if(c == '4'){
                four = true;
                a += "2";
                b += "2";
            }
            else{
                a += c;
                if(four) b += "0";
            }
        }
        cout << "Case #" << z << ": " << a << " " << b << endl;
    }
}

