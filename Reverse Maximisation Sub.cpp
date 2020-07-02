#include<bits/stdc++.h>

using namespace std;

int reverse(int n){
    int res = 0;
    while(n){
        res = (res * 10) + (n % 10);
        n /= 10;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    ofstream op;
    op.open("sub.txt");
    int n = 1;
    while(t--){
        //int n;
        //cin >> n;
        int mx = -1, mxn = -1;
        for(int i = 0; i <= n; i++){
            //op << reverse(i) << endl;
            if(reverse(i) > mx) mx = reverse(i), mxn = i;
        }
        op << mxn << endl;
        //cout << mxn << endl;
        n++;
    }
}