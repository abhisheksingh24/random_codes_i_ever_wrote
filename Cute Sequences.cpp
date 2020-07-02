#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int lastInd(long long a, long long b, long long m){
    for(int i = 0; i < 49; i++){
        long long lim = INF / (a + 1);
        long long mn = (a + 1) * min(lim, 1LL << i);
        lim = INF / (a + m);
        long long mx = (a + m) * min(lim, 1LL << i);
        if(mn <= b && mx >= b) return i;
    }
    return -1;
}

int main(){
    int q;
    cin >> q;
    while(q--){
        long long a, b, m;
        cin >> a >> b >> m;
        if(a == b){
            cout << 1 << " " << a << endl;
            continue;
        }
        int l = lastInd(a, b, m);
        if(l == -1) cout << -1 << endl;
        else {
            //cout << "raw seq: "; for(int i = 0; i <= l; i++) cout << (a + 1) * (1LL << i) << " "; cout << endl;
            long long rem = b - (a + 1) * (1LL << l);
            //cout << rem << " remaining\n";
            vector<long long> r(l + 1);
            for(int i = 0; i < l; i++){
                r[i] = min(m - 1, rem / (1LL << (l - i - 1)));
                rem -= r[i] * (1LL << (l - i - 1));
            }
            r[l] = rem;
            vector<long long> seq;
            seq.push_back(a);
            long long s = a;
            for(int i = 0; i <= l; i++){
                seq.push_back(s + 1 + r[i]);
                s += seq.back();
            } 
            cout << seq.size();
            for(auto& i: seq) cout << " " << i;
            cout << endl;
        }
    }
}