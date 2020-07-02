#include<bits/stdc++.h>

using namespace std;

int bits(int n) { 
    int cnt = 0; 
    while (n) 
    { 
    n &= (n-1) ; 
    cnt++; 
    } 
    return cnt; 
} 

int main(){
    long long n, p;
    cin >> n >> p;
    for(int b = 0; b < 1000; b++){
        if(n - b * p >= 0 && bits(n - b * p) == b){
            cout << b << endl;
            return 0;
        } 
    }
    cout << -1 << endl;
}