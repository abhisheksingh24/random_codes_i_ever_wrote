#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > pop, dist;

long long sumOfPop(){
    long long res = 0;
    for(auto row: pop){
        for(auto p: row) res+=p;
    }
    return res;
}

int remain(int i, int j, int n, int m){
    return (m-j + m*(n-i-1)); 
}

void setDistricts(int n, int m, int k){
    int i = 0, j = 0, step = 1;
    int cur = 0;
    long long tot = 0;
    long long optimal = sumOfPop()/k;
    while(i < n){
        if(cur==0){
            dist[i][j] = ++cur;
            tot = pop[i][j];
        }
        else if(remain(i, j, n, m) == k-cur){
            dist[i][j] = ++cur;
            tot = pop[i][j];
        }
        else if(cur==k){
            dist[i][j] = cur;
            tot+=pop[i][j];
        }
        else if(tot+pop[i][j] <= 2*optimal - tot){
            dist[i][j] = cur;
            tot+=pop[i][j];
        }
        else{
            dist[i][j] = ++cur;
            tot = pop[i][j];
        }
        if(j+step >= m || j+step < 0){
            i++;
            step*=(-1);
        }
        else j+=step;
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    pop.resize(n);
    dist.resize(n);
    for(int i = 0; i < n; i++){
        pop[i].resize(m);
        dist[i].resize(m);
        for(int j = 0; j < m; j++) cin >> pop[i][j];
    }
    setDistricts(n, m, k);
    for(auto row: dist){
        for(auto d: row) cout << d << " ";
        cout << endl;
    }
}