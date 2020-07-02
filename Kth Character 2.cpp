#include<iostream>

using namespace std;

char character(long long k, long long n, bool change){
    if(k==n/2){
        if(change) return 'c';
        else return 'a';
    }
    if(k<n/2) return character(k,n/2,change);
    return character(n-1-k,n/2,!change);
}

int main(){
    int t;
    long long k, lim =  4611686018427387903;
    cin >> t;
    while(t--){
        cin >> k;
        cout << character(k-1, lim, false) << endl;
    }
}
