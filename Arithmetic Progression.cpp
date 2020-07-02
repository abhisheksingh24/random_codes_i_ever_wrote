#include<bits/stdc++.h>

using namespace std;

const int LIM = 1e9;

int cnt = 0;

int lastElement(int l = 0, int r = LIM){
    if(l == r) return l;
    int m = l + (r-l)/2;
    cout << "> " << m << endl; cout.flush();
    int reply;
    cin >> reply;
    cnt++;
    if(reply) return lastElement(m+1, r);
    return lastElement(l, m);
}

int query(int i){
    cout << "? " << i << endl; cout.flush();
    int reply;
    cin >> reply;
    return reply;
}

void factorise(set<int>& factors, int n){
    for(int i = 1; i*i <= n; i++){
        if(n%i) continue;
        factors.insert(i);
        factors.insert(n/i);
    }
}

int main(){
    int n;
    cin >> n;
    int mx = lastElement();
    vector<int> vec;
    for(int i = 1; i <= n && cnt < 60; ++i, ++cnt){
        vec.push_back(query(i));
    }
    sort(vec.begin(), vec.end());
    int pivot = vec.back();
    if(pivot == mx) pivot = vec[vec.size() - 2];
    set<int> possible;
    factorise(possible, mx - pivot);
    for(int x: vec){
        if(possible.size() == 1) break;
        for(auto it = possible.begin(); it != possible.end(); ){
            int d = *it;
            if((mx - x) % d) it = possible.erase(it);
            else if((mx-x)/d > n-1) it = possible.erase(it);
            else ++it;
        }
    }
    int d = *possible.begin();
    int a1 = mx - (n-1) * d;
    cout << "! " << a1 << " " << d << endl; cout.flush();
}