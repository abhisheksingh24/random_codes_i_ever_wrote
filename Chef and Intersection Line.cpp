#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int divider = (m > n ? 2 : 1);
    for(int i = 0; i < m; i++){
        vector<vector<int> > mat;
        mat.resize(n);
        for(int j = 0; j < n; j++){
            mat[j].resize(n);
            for(int k = 0; k < n; k++){
                cin >> mat[j][k];
            }
        }
        if(i/divider < n){
            int mx = 0, x = i/divider, y = 0;
            for(int j = 0; j < n; j++){
                if(mat[i/divider][j] > mx){
                    x = i/divider;
                    y = j;
                    mx = mat[i/divider][j];
                }
            }
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
    if(n < m) cout << "-1 -1\n";
}
