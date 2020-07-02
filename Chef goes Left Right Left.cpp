#include<iostream>
#include<vector>
#include<limits>

using namespace std;

vector<int> ar;

bool possible(int n, int val){
    int mi = numeric_limits<int>::min();
    int mx = numeric_limits<int>::max();
    for(int i = 1; i < n; i++){
        //cout << "i = "  << i+1 << endl;
        //cout << mi << " to " << mx << endl;
        if(ar[i-1] > ar[i]) mx = ar[i-1];
        else mi = ar[i-1];
        if(ar[i] <= mi || ar[i] >= mx) return false;
    }
    return val==ar[n-1];
}

int main(){
    int t, n, r;
    cin >> t;
    while(t--){
        cin >> n >> r;
        ar.resize(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
        }
        if(possible(n, r)) cout << "YES\n";
        else cout << "NO\n";
    }
}
