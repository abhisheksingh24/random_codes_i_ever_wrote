#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > order;
    for(int i = 1; i <= n / 2; i++){
        for(int j = 1; j <= m; j++){
            if(i%2){
                order.emplace_back(i, j);
                order.emplace_back(n - i + 1, m - j + 1);
            }
            else{
                order.emplace_back(i, m - j + 1);
                order.emplace_back(n - i + 1, j);
            }
        }
    }
    if(n%2){
            for(int i = 1, j = m; j > i; i++, j--){
                order.emplace_back(n / 2 + 1, i);
                order.emplace_back(n / 2 + 1, j);
            }
            if(m % 2) order.emplace_back(n / 2  + 1, m / 2 + 1);
    }
    for(auto p: order){
        cout << p.first << " " << p.second << endl;
    }
}