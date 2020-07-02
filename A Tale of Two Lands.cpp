#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a){
        cin >> i;
        if(i < 0) i *= - 1;
    }
    sort(a.begin(), a.end());
    long long res = ((long long)n * (n - 1)) / 2;
    for(int i: a){
        auto it = lower_bound(a.begin(), a.end(), (i + 1) / 2);
        res -= (it - a.begin());
    }
    cout << res << endl;
}