/*https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h */

#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;
vector<int> A, pre;
vector<vector<long long> > dp;

typedef long long ll;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return (-l.k) * x - l.m;
	}
};

void init(int n, int z){
    A.resize(n + 1);
    pre.resize(n);
    dp.clear();
    dp.resize(n + 1, vector<long long>(n + 1));
}

void prefix(int n){
    pre[0] = A[0];
    for(int i = 1; i < n; i++) pre[i] = A[i] + pre[i - 1];
}



int solve(int n, int z){
    if(n < z) return INF;
    if(z == 0) return 0;
    if(n == z) return pre[n - 1];
    if(dp[n - 1][z - 1] != -1) return dp[n - 1][z - 1];
    int res = INF;
    for(int i = z; i < n; i++){
        int cur = A[i - 1] * (n - i) + solve(i, z);
        res = min(res, cur);
    }
    res = min(res, A[n - 1] + solve(n - 1, z - 1));
    dp[n - 1][z - 1] = res;
    return dp[n - 1][z - 1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, z;
        cin >> n >> z;
        init(n, z);
        for(int i = 1; i <= n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        vector<LineContainer> cht(n + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(i == j) dp[i][j] = A[i] + dp[i - 1][j - 1];
                else dp[i][j] = min(A[i] + dp[i - 1][j -1], cht[j].query(i));
                cht[j].add(A[i], -dp[i][j] + A[i] * i);
                /*
                for(int k = j; k <= i; k++){
                    dp[i][j] = min(dp[i][j], A[k] * (i - k) + dp[k][j]);    
                }
                */
            }
        }
        cout << dp[n][z] << endl;
    }
}