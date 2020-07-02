#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1000000007;

vector<int> A;
vector<vector<long long> > cnt;
int n;

int main(){
	int m, l, r, x;
	cin >> n;
	A.resize(n);
	for(int& i: A) cin >> i;
	cnt.resize(n+1);
	for(auto& r: cnt) r.resize(256, 0);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 255; j++){
			cnt[i][j] = cnt[i-1][j];
		}
		cnt[i][A[i-1]]++;
	}
	cin >> m;
	while(m--){
		cin >> l >> r >> x;
		long long res = 0;
		for(int i = 0; i <= 255; i++){
			for(int j = i+1; j <= 255; j++){
				for(int k = j+1; k <= 255; k++){
					if((i & j & k) == x) res = (res + 6*(cnt[r][i] - cnt[l-1][i])*(cnt[r][j] - cnt[l-1][j])*(cnt[r][k] - cnt[l-1][k]))%MOD; 
				}
			}
		}
		for(int i = 0; i <= 255; i++){
			for(int j = i+1; j <= 255; j++){
				if((i & i & j) == x) res = (res + 6*(cnt[r][i] - cnt[l-1][i])*(cnt[r][i] - cnt[l-1][i] - 1)*(cnt[r][j] - cnt[l-1][j]))%MOD;
			}
		}
		for(int i = 0; i <= 255; i++){
			if((i & i & i) == x) res = (res + 6*(cnt[r][i] - cnt[l-1][i])*(cnt[r][i] - cnt[l-1][i] - 1)*(cnt[r][i] - cnt[l-1][i] - 2))%MOD;
		}
		cout << res << endl;
	}
}
