#include<bits/stdc++.h>

using namespace std;

int main(){
    random_device dev;
    mt19937 rng(dev());
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        uniform_int_distribution<mt19937::result_type> r2(1,n);
        vector<vector<int> > co(n, vector<int>(4));
        vector<int> dir(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 4; ++j) cin >> co[i][j];
            cin >> dir[i];
        }
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            int x = r2(rng);
            if(s == "REVERSE") cout << x << " " << i + 1 << endl;
            else cout << x << " "  << (dir[x - 1] = (dir[x - 1] + 1) % 4) << " " << i + 1 << endl;
        }
    }
}