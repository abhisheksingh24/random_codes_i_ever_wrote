#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define X 131072

vector<int> vec;
map<int, long long> cnt;

void init(int n){
    vec.clear();
    vec.resize(n);
    cnt.clear();
}

void fillCounts(int n){
    for(int i = 0; i < n; i++){
        if(cnt.find(vec[i]) != cnt.end()) cnt[vec[i]]++;
        else cnt[vec[i]] = 1;
    }
}

long long two(){
    long long res = 0;
    for(int i : vec){
        if(cnt.find(i^2)==cnt.end()) continue;
        res+=(cnt[i]*cnt[i^2]);
        //if((cnt[i]*cnt[i^2]) > 0) cout << i << " " << (i^2) << endl;
    }
    return res/2;
}

long long zero(){
    long long res = 0;
    for(int i : vec){
        res+=((cnt[i]*(cnt[i]-1))/2);
    }
    return res;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        init(n);
        for(int i = 0; i < n; i++) cin >> vec[i];
        long long odd = 0, even = 0;
        for(int i : vec){
            if(i%2) odd++;
            else even++;
        }
        long long total = (odd*(odd-1))/2 + (even*(even-1))/2;
        fillCounts(n);
        //cout << "total = " << total << endl;
        //cout << "two  = " << two() << endl;
        //cout << "zero = " << zero() << endl;
        total -= two();
        total -= zero();
        cout << total << endl;
    }
}
