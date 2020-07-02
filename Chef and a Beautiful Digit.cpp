#include<bits/stdc++.h>

using namespace std;

vector<int> dig, res;

int main(){
    long long t, n, d;
    cin >> t;
    while(t--){
        dig.clear(); res.clear();
        cin >> n >> d;
        while(n){
            dig.push_back(n%10);
            n/=10;
        }
        reverse(dig.begin(), dig.end());
        for(int i: dig){
            while(!res.empty() && i < res.back()) res.pop_back();
            res.push_back(i);
        }
        while(!res.empty() && d < res.back()) res.pop_back();
        while(res.size() < dig.size()) res.push_back(d);
        for(int i: res) cout << i;
        cout << endl;
    }
}