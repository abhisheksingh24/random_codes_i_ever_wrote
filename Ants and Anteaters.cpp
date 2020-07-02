#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        vector<string> mat(r);
        vector<vector<bool> > eat(r, vector<bool>(c, false));
        vector<int> x, y;
        vector<char> d;
        for(string& s: mat) cin >> s;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == '#') eat[i][j] = true;
                else if(mat[i][j] == '-') continue;
                x.push_back(i);
                y.push_back(j);
                d.push_back(mat[i][j]);
            }
        }
        long long res = 0;
        for(int i = 0; i < max(r, c) + 5; i++){
            vector<vector<int> > ant(r, vector<int>(c, 0));
            for(int j = 0; j < x.size(); j++){
                if(x[j] == -1) continue;
                ant[x[j]][y[j]]++;
                if(d[j] == 'U') x[j]--;
                else if(d[j] == 'D') x[j]++;
                else if(d[j] == 'L') y[j]--;
                else if(d[j] == 'R') y[j]++;
                if(x[j] >= r || y[j] >= c || x[j] < 0 || y[j] < 0 || eat[x[j]][y[j]]){
                    x[j] = y[j] = -1;
                    continue;
                }
            }
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    //cout << ant[j][k] << " ";
                    res += (ant[j][k] * (ant[j][k] - 1)) / 2;
                }
                //cout << endl;
            }
            //cout << endl;
        }
        cout << res << endl;
    }
}