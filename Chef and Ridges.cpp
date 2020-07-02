#include<iostream>
#include<vector>

using namespace std;

vector<pair<long long, long long> > dp;

long long gcd(long long a, long long b) { 
    if (b == 0) return a; 
    return gcd(b, a % b);
} 

pair<long long, long long> reduce(long long num, long long den){
    long long g = gcd(num, den);
    return make_pair(num/g, den/g);
}

void fillDP(long long cur, pair<long long, long long> l, pair<long long, long long> r, bool edge){
    if(cur > 25) return;
    //cout << cur << endl;
    long long den = 2 * l.second * r.second;
    long long num = l.first * r.second + r.first * l.second;
    pair<long long, long long> ridge = reduce(num, den);
    dp.push_back(ridge);
    if(edge) fillDP(cur+1, l, ridge, !edge);
    else fillDP(cur+1, ridge, r, !edge);
}

int main(){
    long long t, n;
    fillDP(1, make_pair(0, 1), make_pair(1, 1), 1);
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n-1].first << " " << dp[n-1].second;
        if(t) cout <<" ";
        else cout << endl;
    }
}