#include<iostream>
#include<vector>

using namespace std;

vector<long long> cnt;

void precompute(int n, int m){
    for(int i = 0; i < m; i++) cnt.push_back(0);
    for(long long i = 0; i < m; i++){
        cnt[(i*i)%m] += n/m;
    }
    for(long long i = (n/m)*m; i <= n; i++){
        cnt[(i*i)%m]++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    precompute(n, m);
    long long res = (cnt[0]*(cnt[0]-1))/2;
    for(int i = 1; i < m; i++){
        if(i == m-i) res += (cnt[i]*(cnt[i] - 1)) / 2; 
        res += cnt[i]*cnt[m-i];
    }
    cout << res << endl;
}