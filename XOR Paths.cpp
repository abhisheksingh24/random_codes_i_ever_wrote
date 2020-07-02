/*
https://github.com/mochow13/competitive-programming-library/blob/master/Math/Fast%20Walsh-Hadamard%20Transform.cpp
*/

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1<<17;

template <typename T>
struct FWT {
	void fwt(T io[], int n) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d<<1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget modulo if required
					T x = io[i+j], y = io[i+j+d];
					io[i+j] = (x+y), io[i+j+d] = (x-y);	// xor
					// io[i+j] = x+y; // and
					// io[i+j+d] = x+y; // or
				}
			}
		}
	}
	void ufwt(T io[], int n) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d<<1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget modulo if required
					T x = io[i+j], y = io[i+j+d];
					 /// Modular inverse if required here
					io[i+j] = (x+y)>>1, io[i+j+d] = (x-y)>>1; // xor
					// io[i+j] = x-y; // and
					// io[i+j+d] = y-x; // or
				}
			}
		}
	}
	// a, b are two polynomials and n is size which is power of two
	void convolution(T a[], T b[], int n) {
		fwt(a, n);
		fwt(b, n);
		for (int i = 0; i < n; i++)
			a[i] = a[i]*b[i];
		ufwt(a, n);
	}
	// for a*a	
	void self_convolution(T a[], int n) {
		fwt(a, n);
		for (int i = 0; i < n; i++)
			a[i] = a[i]*a[i];
		ufwt(a, n);
	}
};
FWT<long long> fwt;

vector<vector<pair<int, int> > > tree;

long long d[N];

void dfs(int r, int w, int par = -1){
    for(auto p: tree[r]){
        if(p.first == par) continue;
        d[w ^ p.second]++;
        dfs(p.first, w ^ p.second, r);
    }
}

int main(){
    int n;
    cin >> n;
    tree.resize(n);
    for(int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        tree[x].emplace_back(y, z);
        tree[y].emplace_back(x, z);
    }
    for(int i = 0; i < N; i++) d[i] = 0;
    d[0] = 1;
    dfs(0, 0);
    long long sub = 0;
    fwt.self_convolution(d, N);
    for(int i = 0; i < N; i++) d[i] %= MOD;
    long long res = 0;
    for(int i = 0; i < N; i++){
        res += d[i] * d[i];
        res %= MOD;
        for(int j = 1; j <= i; j *= 2){
            if(i & j){
                res += 2 * d[i] * d[i - j];
                res %= MOD;
            }
        }
    }
    cout << res << endl;
}