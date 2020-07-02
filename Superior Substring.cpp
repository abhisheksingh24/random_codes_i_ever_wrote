#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

vector<vector<int> > pos;
vector<int> cnt;
int n;

int main(){
	int t;
	string s;
	cin >> t;
	pos.resize(26);
	while(t--){
		int mx = 3;
		cin >> n;
		for(auto& i: pos) i.clear();
		cnt.clear();
		cnt.resize(26, 0);
		cin >> s;
		for(int i = 0; i < n; ++i){
			int id = s[i] - 'a';
			int c = ++cnt[id];
			for(int p: pos[id]){
				if(2*c + 1 <= mx) break;
				if(2*c + 1 >= i-p+1){
					mx = 2*c + 1;
					break;
				}
				--c;
			}
			pos[id].push_back(i);
		}
		cout << min(mx, n) << endl;
	}
}
