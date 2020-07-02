#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    bool inc = true;
    for(int& i: a){
        if(i % 2 == 0) i /= 2;
        else{
            if(i > 0) i /= 2;
            else i = (i - 1) / 2;
            if(inc) i++, inc = false;
            else inc = true;
        }
    }
    for(int& i: a) cout << i << " ";
    cout << endl; 
}