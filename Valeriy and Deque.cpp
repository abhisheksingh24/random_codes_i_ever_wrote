#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    int mx = *max_element(a.begin(), a.end());
    deque<int> dq;
    for(int i: a) dq.push_back(i);
    vector<pair<int, int> > pickup;
    while(dq.front() != mx){
        int A = dq.front();
        dq.pop_front();
        int B = dq.front();
        dq.pop_front();
        pickup.emplace_back(A, B);
        if(A < B) swap(A, B);
        dq.push_front(A);
        dq.push_back(B);
    }
    vector<int> aa;
    for(auto it = dq.begin(); it != dq.end(); it++){
        aa.push_back(*it);
    }
    while(q--){
        long long m;
        cin >> m;
        if(m <= pickup.size()){
            cout << pickup[m - 1].first << " " << pickup[m - 1].second << endl;
            continue;
        }
        m -= pickup.size();
        m--;
        m %= (n - 1);
        m++;
        cout << aa[0] << " " << aa[m] << endl;
    }    
}