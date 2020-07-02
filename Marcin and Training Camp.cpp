#include<bits/stdc++.h>

using namespace std;

long long oc(long long n, long long m) { 
   int number_of_bits = floor(log2(max(n, m)))+1; 
   return ((1LL << number_of_bits) - 1) ^ n; 
}

int main(){
    
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> b(n);
    for(auto& i: a) cin >> i;
    for(auto& i: b) cin >> i;
    set<int> rem;
    for(int i = 0; i < n; i++) rem.insert(i);
    vector<set<int> > cool(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(!(a[i] & oc(a[j], a[i]))) cool[i].insert(j);
        }
    }
    bool changing = true;
    vector<int> zero;
    for(int i = 0; i < n; i++) if(cool[i].empty()) zero.push_back(i);
    while(!zero.empty()){
        vector<int> nxt;
        for(int& i: zero){
            rem.erase(i);
            for(auto& s: cool){
                s.erase(i);
                if(s.empty()) nxt.push_back(j);
            }
        }
        zero = nxt;
    }
    long long res = 0;
    for(int i: rem) res += b[i];
    cout << res << endl;
}