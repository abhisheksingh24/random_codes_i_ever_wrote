#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;

void init(int n){
    a.clear();
    a.resize(n);
}

long long wait(long long start, long long cur, long long q, int l){
    long long finish = start + (q+1)*l;
    return max(finish-cur, (long long)0);
}

long long solve(int n, int m, int k, int l){
    long long curTime = 0, curQueue = m;
    long long minWait = wait(curTime, 0, curQueue, l);
    for(int i = 0; i < n; i++){
        long long newTime = (a[i]/l)*l;
        curQueue -= (newTime-curTime)/l;
        if(curQueue <= -1){
            curTime = a[i];
            curQueue = -1;
        }
        else curTime = newTime;
        minWait = min(minWait, wait(curTime, a[i], curQueue, l));
        //cout << a[i] << " : " << minWait << endl;
        curQueue++;
    }
    minWait = min(minWait, wait(curTime, k, curQueue, l));
    return minWait;
}

int main(){
    int t, n, m, k, l;
    cin >> t;
    while(t--){
        cin >> n >> m >> k >> l;
        init(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << solve(n, m, k, l) << endl;
    }
}