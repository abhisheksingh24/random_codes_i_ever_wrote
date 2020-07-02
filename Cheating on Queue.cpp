#include<bits/stdc++.h>

using namespace std;

vector<int> a, den, open, close;
vector<bool> check;
//set<pair<int, int> > order;
long long sum;

bool canStandAt(int pos, int n, int k){
    sum -= a[pos-1]/den[pos-1];
    den[pos-1] = a[pos-1] + 1;
    if(!check[pos]) return false;
    //order.erase(make_pair(-a[pos-1], pos-1));
    for(int i = pos; i < n; ++i){
        if(sum > k) return false;
        sum -= a[i]/den[i];
        den[i] = i - pos + 1;
        sum += a[i]/den[i];
    }
    return sum <= k;
}

int solve(int n, int k, int beg){
    if(sum <= k) return beg+1;
    for(int i = beg+1; i < n; i++) if(canStandAt(i, n, k)) return i+1;
    return n+1;
}

int maxDen(int num, int k){
    int l = 1, r = num;
    while(l < r){
        int m = l + (r-l)/2;
        if(num/m <= k) r = m;
        else l = m + 1;
    }
    return l;
}

int bestCase(vector<int> a, int n, int k){
    sort(a.begin(), a.end());
    long long tot = 0;
    int cnt = 0;
    for(int i = 0; i < n && tot <= k; ++i, ++cnt){
        tot += a[i]/(i+1);
    }
    return cnt-1 + (tot<=k);
}

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        a.clear();
        den.clear();
        open.clear();
        close.clear();
        check.clear();
        open.resize(n, 0);
        close.resize(n, 0);
        check.resize(n, true);
        //order.clear();
        a.resize(n);
        int mx = bestCase(a, n, k);
        for(int& i: a) cin >> i;
        for(int i = 0; i < n; i++){
            ++open[max(0, i - maxDen(a[i], k)  + 1)];
            ++close[i];
        }
        int depth = 0;
        for(int i = n-1; i ; --i){
            depth += (close[i] - open[i]);
            if(depth) check[i] = false;
        }
        for(int i = 0; i < n-mx; ++i) den.push_back(a[i] + 1);
        for(int i = n-mx, d = 1; i < n; i++, ++d) den.push_back(d);
        sum = 0;
        for(int i = 0 ; i < n; ++i) sum += a[i]/den[i];
        //for(int i = 0; i < n; i++) order.emplace(-a[i], i);
        cout << solve(n, k, n-mx) << endl;
    }
}