#include<iostream>
#include<vector>

using namespace std;

int n, a, b;
vector<int> cnt;
vector<bool> type;
vector<pair<long long, long long> > tot;

long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}

pair<long long, long long> findRatio(){
    a = 0, b = 0;
    tot.emplace_back(a, b);
    for(int i = 0; i < n; i++){
        if(type[i]) a += cnt[i];
        else b += cnt[i];
        tot.emplace_back(a, b);
    }
    long long g = gcd(a, b);
    return make_pair(a/g, b/g);
}

long long solve(pair<long long, long long> r){
    if(r.first == 0) return b;
    if(r.second == 0) return a;
    long long req, res = 0;
    for(int i = 1; i < n; i++){
        if(type[i]){
            if(tot[i].second % r.second == 0){
                req = tot[i].second/r.second * r.first - tot[i].first;
                if(req >= 0 && req < cnt[i]) res++;  
            }
        }
        else{
            if(tot[i].first % r.first == 0){
                req = tot[i].first/r.first * r.second - tot[i].second;
                if(req >= 0 && req < cnt[i]) res++;  
            }
        }
    }
    return res+1;   
}

int main(){
    int t, k;
    char c;
    cin >> t;
    while(t--){
        cnt.clear();
        type.clear();
        tot.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> k >> c;
            cnt.push_back(k);
            type.push_back(c=='A');
        }
        pair<long long, long long> r = findRatio();
        cout << solve(r) << endl;
    }
}