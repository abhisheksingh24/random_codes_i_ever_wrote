#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> linked[3001];
vector<int> volume;
vector<int> parent;
long long subTreeVol[3001];
bool visited[3001];

void init(int n){
    for(int i = 0; i <= n; i++) visited[i] = false;
}

long long fillSubTree(int i){
    visited[i] = true;
    long long sumVol = volume[i];

    for(int j =0, l = linked[i].size(); j < l; j++){
        if(!visited[linked[i][j]]) sumVol+=fillSubTree(linked[i][j]);
        parent[linked[i][j]] = i;
    }
    subTreeVol[i] = sumVol;
    return subTreeVol[i];
}

bool isParent(int p, int c){
    while(c!=1 && c!=p){
        c = parent[c];
    }
    return c==p;
}

long long max3(long long a, long long b, long long c){
    return max(a,max(b,c));
}

long long solve(int n){
    fillSubTree(1);
    //cout << "Filled Tree\n";
    long long minMax = LONG_MAX;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            //cout << "i = " << i << " j = " << j << endl;
            if(i==j) continue;
            if(isParent(i,j)) minMax = min(minMax, max3(subTreeVol[1]-subTreeVol[i], subTreeVol[i]-subTreeVol[j], subTreeVol[j]));
            else if(isParent(j,i)) minMax = min(minMax, max3(subTreeVol[1]-subTreeVol[j], subTreeVol[j]-subTreeVol[i], subTreeVol[i]));
            else minMax = min(minMax, max3(subTreeVol[1]-subTreeVol[i]-subTreeVol[j], subTreeVol[i], subTreeVol[j]));
        }
    }
    return minMax;
}

int main(){
    int n, a, b;
    cin >> n;
    init(n);
    volume.resize(n+1);
    parent.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> volume[i];
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }
    //cout << "Input Taken\n";
    cout << solve(n) << endl;
}
