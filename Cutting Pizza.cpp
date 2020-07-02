#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b) { 
    if (b == 0) return a; 
    return gcd(b, a % b);  
} 

int main(){
    int t, n;
    vector<int> cuts;
    cin >> t;
    while(t--){
        cin >> n;
        cuts.clear();
        cuts.resize(n);
        for(int &i: cuts) cin >> i;
        sort(cuts.begin(), cuts.end());
        for(int i = 1; i < n; i++) cuts[i]-=cuts[0];
        cuts[0] = 0;
        int factor = 360;
        for(int i = 1; i < n; i++) factor = gcd(factor, cuts[i]);
        cout << 360/factor - cuts.size() << endl;

    }
}