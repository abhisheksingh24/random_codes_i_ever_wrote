#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    int cur = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] != -1) continue;
        for(int j = i; j <= n; j += i) a[j] = cur;
        cur++;
    }
    for(int i = 2; i <= n; i++) cout << a[i] << " ";
    cout <<endl;
}