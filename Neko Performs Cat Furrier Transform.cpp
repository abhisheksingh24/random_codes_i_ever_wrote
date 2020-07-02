#include<bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    vector<int> res;
    while(true){
        int n = 1, i = 0;
        while(n - 1 < x) n*=2, i++;
        res.push_back(i);
        if(2*x == n) break;
        x = (x ^ (n - 1));
        if(x == 0 || x == 1) break;
        x++;
    }
    cout << res.size() * 2 - 1 << endl;
    for(int i: res) cout << i << " ";

}