#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, a, b, x, y, z;
    vector<long long> g(1);
    cin >> n >> m >> a >> b;
    cin >> g[0] >> x >> y >> z;
    for(int i = 1; i < m * n; i++) g.push_back((g.back() * x + y) % z);
    vector<vector<int> > mat(n, vector<int>(m)), mxrow(n, vector<int>(m - b + 1)), mx(n - a + 1, vector<int>(m - b + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = g[i * m + j];
        }
    }
    for(int i = 0; i < n; i++){
        deque<int> nums;
        for(int j = 0; j < b - 1; j++){
            while(!nums.empty() && mat[i][nums.back()] >= mat[i][j]) nums.pop_back();
            nums.push_back(j);
        }
        for(int j = 0; j < m - b + 1; j++){
            while(!nums.empty() && mat[i][nums.back()] >= mat[i][j + b - 1]) nums.pop_back();
            nums.push_back(j + b - 1);
            mxrow[i][j] = mat[i][nums.front()];
            if(nums.front() == j) nums.pop_front();
        }
    }
    for(int j = 0; j < m - b + 1; j++){
        deque<int> nums;
        for(int i = 0; i < a - 1; i++){
            while(!nums.empty() && mat[nums.back()][j] >= mat[i][j]) nums.pop_back();
            nums.push_back(i);
        }
        for(int i = 0; i < n - a + 1; i++){
            while(!nums.empty() && mat[nums.back()][j] >= mat[i + a - 1][j]) nums.pop_back();
            nums.push_back(i + a - 1);
            mx[i][j] = mxrow[nums.front()][j];
            if(nums.front() == i) nums.pop_front();
        }
    }
    long long res = 0;
    for(auto& row: mx) for(int& i: row) res += i;
    cout << res << endl;
}