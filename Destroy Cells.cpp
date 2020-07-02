#include<bits/stdc++.h>

using namespace std;

pair<int, int> nxt(pair<int, int> cur, int k, int n, int m){
    k++;
    cur.first += k / m;
    cur.second += k % m;
    if(cur.second >= m) cur.first++, cur.second %= m;
    return cur;
}

bool destroyed(int x, int y, int n, int m, int k){
    int dist  = y * n + x;
    return dist % (k + 1) == 0; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int k = 0; k < n * m; k++){
 
            int cnt = (n * m + k) / (k + 1);
            pair<int, int> cur = make_pair(0, 0);

            while(cur.first < n && cur.second < m){
                if(!destroyed(cur.first, cur.second, n, m, k)) cnt++;
                cur = nxt(cur, k, n, m);
            }
            cout << cnt << " "; 
        }
        cout << endl;
    }
}