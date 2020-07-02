#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<bool> box(n, false);
    for(int& i: A) cin >> i;
    int m = 0;
    for(int i = n - 1; i >= 0; i--){
        int cnt = 0;  
        for(int j = i + 1; j <= n; j += i + 1){
            cnt += box[j - 1];
        }
        cnt %= 2;
        if(cnt != A[i]) box[i] = true, m++;
    }
    cout << m << endl;
    for(int i = 0; i < n; i++) if(box[i]) cout << i + 1 << " ";
    cout << endl;
}