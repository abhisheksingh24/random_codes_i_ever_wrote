#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

vector<vector<int> > unit = {{1, 0, 0},
                            {0, 1, 0},
                            {0, 0, 1}};

void multiply(vector<vector<int> > a, vector<vector<int> > b, vector<vector<int> >& res){
    int siz = a.size();
    for(int i = 0; i < siz; i++){
        for(int j = 0; j < siz; j++){
            long long s = 0;
            for(int k = 0; k < siz; k++){
                s = (s + ((long long)(a[i][k])*b[k][j])) % MOD;
            }
            res[i][j] = (int)(s);
        }
    }
}

void matMod(vector<vector<int> > mat, int m){
    int l = mat.size();
    for(int i = 0; i < l; i++){
        int l2 = mat[i].size();
        for(int j = 0; j < l2; j++){
            mat[i][j] = mat[i][j] % m;
        }
    }
}

vector<vector<int> > power(vector<vector<int> > mat, int p, int m){
    //cout << "calculating power\n";
    vector<vector<int> > res(unit);
    matMod(mat, MOD);//x = x % p;
    while (p > 0){
        if (p & 1){
            multiply(res, mat, res);
            matMod(res, m);
        }
        p = p>>1;
        multiply(mat, mat, mat);//x = (x*x) % p;
        matMod(mat, m);
    }
    //cout << "calculated power\n";
    return res;
}

int sumUpto(int n, vector<vector<int> > &mat, vector<vector<int> > &base){
    if(n<0) return 0;
    vector<vector<int> > m = power(mat, n-1, MOD);
    vector<vector<int> > res;
    res.resize(3);
    for(int i = 0; i < 3; i++) res[i].resize(1);
    multiply(m, base, res);
    return res[0][0]%MOD;
}

int main(){
    int t, n, m;
    cin >> t;
    vector<vector<int> > mat = {{1, 1, 1},
                                {0, 1, 1},
                                {0, 1, 0}},
                        base = {{1},
                                {1},
                                {0}};

    while(t--){
        cin >> n >> m;
        int s1 = sumUpto(n-1, mat, base);
        int s2 = sumUpto(m, mat, base);
        cout << (s2-s1+MOD)%MOD << endl;
    }
}
