#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s;
    vector<int> p, order; 
    for(int i = 0; i < n; i++){
        string ss;
        int pp;
        cin >> ss >> pp;
        s.push_back(ss);
        p.push_back(pp);
    }
    vector<bool> done(n, false);
    for(int i = 1; i <= n; i++){
        int mn = -1;
        for(int j = 0; j < n; j++){
            if(done[j]) continue;
            if(mn == -1) mn = j;
            else if(s[j] < s[mn]) mn = j;
            else if(s[j] == s[mn] && p[j] > p[mn]) mn = j;
        }
        order.push_back(mn + 1);
        done[mn] = true;
    }
    for(int& i: order) cout << i << endl;
}