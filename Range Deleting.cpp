#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for(long long& i: a) cin >> i;
    long long curMax = -1;
    vector<long long> toDel;
    for(long long i: a){
        if(i >= curMax){
            curMax = i;
        }
        else{
            toDel.push_back(i);
        }
    }
    if(toDel.empty()) cout << x * (x - 1) / 2 << endl;
    else{
        long long mn, mx;
        mn = *min_element(toDel.begin(), toDel.end());
        mx = *max_element(toDel.begin(), toDel.end());
        cout << mn * (x - mx + 1) << endl;
    }
}