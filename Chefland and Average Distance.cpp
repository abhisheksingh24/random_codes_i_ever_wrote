#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<bool> > mat;
vector<int> res;

int diff(int a, int b){
    int res = a-b;
    if(res < 0) res*=-1;
    return res;
}

int main(){
    int  t, n, m;
    string temp;
    cin >> t;
    while(t--){
        mat.clear();
        res.clear();
        cin >> n >> m;
        mat.resize(n);
        res.resize(n+m);
        for(int i = 0; i < n+m; i++) res[i] = 0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            mat[i].resize(m);
            for(int j = 0; j < m; j++){
                mat[i][j] = (temp[j] == '1');
            }
        }
        for(int i =0 ; i < n; i++){
            for(int j = 0 ; j  < m; j++){
                for(int k =0 ; k < n; k++){
                    for(int l = 0 ; l < m; l++){
                        if(mat[i][j] && mat[k][l]){
                            int d = diff(i, k) + diff(j, l);
                            res[d]++;
                        }
                    }
                }       
            }
        }
        for(int i = 1; i <= n+m-2; i++){
            cout << res[i]/2 << " ";
        }
        cout << endl;
    }
}