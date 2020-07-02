#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int> > mat;
        mat.resize(n);
        for(int i = 0; i < n; i++){
            mat[i].resize(n);
            for(int j = 0 ; j < n; j++) cin >> mat[i][j];
            sort(mat[i].begin(), mat[i].end());
        }
        long long sum = mat[n-1][n-1];
        int cur = mat[n-1][n-1];
        bool impossible = false;
        for(int i = n-2; i>=0; i--){
            vector<int>::iterator lb = lower_bound(mat[i].begin(), mat[i].end(), cur);
            if(lb == mat[i].begin()){
                impossible = true;
                break;
            }
            cur = *(--lb);
            sum+=cur;
        }
        if(impossible) cout << "-1\n";
        else cout << sum << endl;
    }
}
