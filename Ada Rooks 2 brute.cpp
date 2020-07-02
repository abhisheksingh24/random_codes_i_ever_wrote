#include<bits/stdc++.h>

using namespace std;

void refill(vector<vector<int> > res, set<int>& rows, int i, int j){
    rows.clear();
    for(int k = 0; k < i; ++k){
        for(int l = 0; l < j - 1; l++){
            if(res[k][l] == res[i][l]) rows.insert(k);
        }
    }
}

vector<vector<int> > makeVector(int n){
    vector<vector<int> > res(n, vector<int>(8));
    int lim = n / 8;
    vector<int> minm(8, 0);
    for(int i = 0; i < n; ++i){
        set<int> rows;
        for(int j = 0; j <  8; ++j){
            set<int> filled;
            for(int r: rows) filled.insert(res[r][j]);
            int cur = minm[j];
            while(filled.find(cur) !=  filled.end()) cur++;
            if(cur >= lim){
                if(j == 0){
                    cout << i*8 << " rooks placed\n";
                    return res;
                }
                minm[j-1] = res[i][j - 1] + 1;
                for(int k = j; k < 8; ++k) minm[k] = 0;
                refill(res, rows, i, j);
                j -= 2;
                continue;
            }
            res[i][j] = cur;
            for(int k = 0; k < i; k++) if(res[k][j] == cur) rows.insert(k);
        }
        cout << i << ": ";
        for(int j = 0; j < 8; j++) cout << res[i][j] << " ";
        cout << endl;
    }
}


int main(){
    int n;
    cin >> n;
    int lim = n / 8;
    vector<vector<bool> > board(n, vector<bool>(n));
    vector<vector<int> > attempt = makeVector(n);
    int i = 0;
    for(auto row: attempt){
        int j = 0;
        for(int offset: row){
            board[i][j + offset] = true;
            j += lim;
        }
        i++;
    }
    int cnt = 0;
    for(auto row: board){
        for(auto cell: row){
            if(cell) {cnt++;cout << "O ";}
            else cout << ". ";
        }
        cout << endl;
    }
    cout << cnt << " rooks placed\n";
}