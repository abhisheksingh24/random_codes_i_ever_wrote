#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> type(n), eelLeft(n, 0), eelRight(n, 0), tunaLeft(n, 0), tunaRight(n, 0);
    for(int& i: type) cin >> i;
    for(int i = 0; i < n; i++){
        if(type[i] == 1){
            tunaLeft[i] = 1;
            if(i > 0) tunaLeft[i] += tunaLeft[i-1];
        }
        else{
            eelLeft[i] = 1;
            if(i > 0) eelLeft[i] += eelLeft[i-1];
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(type[i] == 1){
            tunaRight[i] = 1;
            if(i < n-1) tunaRight[i] += tunaRight[i+1];
        }
        else{
            eelRight[i] = 1;
            if(i < n-1) eelRight[i] += eelRight[i+1];
        }
    }

    int mx = 0;
    for(int i = 0; i < n-1; i++){
        int l1, l2, r1, r2;
        l1 = tunaLeft[i];
        l2 = eelLeft[i];
        r1 = eelRight[i+1];
        r2 = tunaRight[i+1];
        mx = max(mx, 2*max(min(l1, r1), min(l2, r2)));
    }
    /*
    for(int i: tunaLeft) cout << i << " "; cout << endl;
    for(int i: eelLeft) cout << i << " "; cout << endl;
    for(int i: tunaRight) cout << i << " "; cout << endl;
    for(int i: eelRight) cout << i << " "; cout << endl;
    */
    cout << mx << endl;
}