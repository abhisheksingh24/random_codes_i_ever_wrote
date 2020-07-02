#include<iostream>
#include<vector>
#include<utility>
#include<string>

using namespace std;

vector<bool> a;
pair<pair<int, int>, pair<int, int>> longest;

int findLength(pair<int, int> p, int n){
    if(p.second == -1) return 0;
    if(p.first <= p.second) return p.second - p.first + 1;
    return n - p.first + p.second + 1;
}

void tryToPush(pair<int, int> p, int n){
    int l1 = findLength(p, n);
    int l2 = findLength(longest.first, n);
    int l3 = findLength(longest.second, n);
    if(l1 > l2 || l1 > l3){
        if(l2 > l3) longest.second = p;
        else longest.first = p; 
    }
}

void preSolve(int n){
    int beg = 0;
    while(beg < n && a[beg]) beg++;
    if(beg==n) beg = 0;
    else while(beg < n && !a[beg]) beg++;
    if(beg==n) beg = 0;

    if(!a[beg]) return;

    pair<int, int> cur = make_pair(beg, beg);
    for(int i = beg+1; i < n; i++){
        if(!a[i]){
            tryToPush(cur, n);
            cur = make_pair(0, -1);
        }
        else if(cur.second==-1) cur = make_pair(i, i);
        else cur.second = i;
    }
    for(int i = 0; i < beg; i++) if(a[i]) cur.second = i;
    tryToPush(cur, n);
}

void shift(int n){
    if(longest.first.first == 0 && longest.first.second == n-1) return;
    if(longest.second.first == 0 && longest.second.second == n-1) return;
    if(longest.first.second != -1){
        longest.first.first = (longest.first.first + 1) % n; 
        longest.first.second = (longest.first.second + 1) % n;
    }
    if(longest.second.second != -1){
        longest.second.first = (longest.second.first + 1) % n;  
        longest.second.second = (longest.second.second + 1) % n;
    }
}

void printMax(int n, int k){
    vector<int> val;
    if(longest.first.second != -1){
        if(longest.first.first <= longest.first.second) val.push_back(longest.first.second - longest.first.first + 1);
        else{
            val.push_back(n - longest.first.first);
            val.push_back(longest.first.second + 1);
        }
    }
    if(longest.second.second != -1){
        if(longest.second.first <= longest.second.second) val.push_back(longest.second.second - longest.second.first + 1);
        else{
            val.push_back(n - longest.second.first);
            val.push_back(longest.second.second + 1);
        }
    }
    int mx = 0;
    for(int i: val) mx = max(mx, i);
    cout << min(k, mx) << endl;
}

int main(){
    int n, q, k;
    string query;
    cin >> n >> q >> k;
    a.resize(n);
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        a[i] = (temp==1);
    }
    cin >> query;

    longest = make_pair(make_pair(0, -1), make_pair(0,-1));
    preSolve(n);
    for(char c: query){
        if(c=='!') shift(n);
        else printMax(n, k);
    }
}