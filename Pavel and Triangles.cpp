#include<bits/stdc++.h>

using namespace std;

vector<int> A;

int main(){
    int n;
    cin >> n;
    A.resize(n);
    for(int& i: A) cin >> i;
    long long res = 0;
    int pending = 0;
    for(int i: A){
        int cur = min(pending, i/2);
        res += cur;
        pending -= cur;
        i -= (2 * cur);
        res += i/3;
        pending += (i % 3);
    }
    cout << res << endl;
}