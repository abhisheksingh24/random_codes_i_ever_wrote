#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

vector<int> findOrder(int n){
    int N = n;
    vector<int> res;
    int step = 2;
    while(n > 1){
        if(n % 2){
            res.push_back(((N - 1) / step) * step);
        }
        n = (n + 1) / 2;
        step *= 2;
    }
    return res;
}

void trans(vector<int>& order, int i, int n){
    int r = n - i;
    for(int& id: order){
        if(id < r) id += i;
        else id -= r, id *= 2;
    }
}

long long sum(vector<int>& ids, vector<int>& A){
    long long res = 0;
    for(int i: ids) res += A[i];
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, f;
        cin >> n;
        vector<int> A(n - 1);
        for(int& i: A) cin >> i;
        cin >> f;
        long long res = INF;
        int p;
        for(int i = 0; i < n; i++){
            if(A[i % (n - 1)] > f) continue;
            int cnt = (i + 1) / 2 + n - i - 1;
            vector<int> order = findOrder(cnt);
            trans(order, i, n - 1);
            long long tot = sum(order, A);
            if(i % 2) tot += A[i -1];
            if(tot < res){
                p = i + 1;
                res = tot;
            }
        }
        if(res == INF) cout << "impossible" << endl;
        else{
            cout << "possible" << endl;
            cout << p << " " << res + f << endl;
        }
    }
}