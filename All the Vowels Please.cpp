#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    int n,m = -1;
    for(n = 5; n <= k/5; n++){
        if(k % n == 0){
            m = k / n;
            break;
        }
    }
    if(m < 5){
        cout << -1 << endl;
        return 0;
    }
    string vowel = "aeiou";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << vowel[(i + j) % 5];
        }
    }
    cout << endl;
}