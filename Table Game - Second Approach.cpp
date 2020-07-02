#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string row, col;
vector <vector <int> > dpRow, dpCol;

void init(int n, int m){
    dpRow.clear();
    dpCol.clear();
    dpRow.resize(2);
    dpCol.resize(2);
    for(int i = 0; i < 2; i++){
        dpRow[i].resize(m);
        dpCol[i].resize(n);
    }
}

void fillDP(int n, int m){
    for(int i = 0; i < min(2, n); i++){
        for(int j = 0; j < m; j++){
            if(i==0){
                if(j==0){
                    if(row[0]=='0' || col[0]=='0') dpRow[i][j] = 1;
                    else dpRow[i][j] = 0;
                }
                else{
                    if(row[j]=='0' || dpRow[i][j-1]==0) dpRow[i][j] = 1;
                    else dpRow[i][j] = 0; 
                }
            }
            else{
                if(j==0){
                    if(col[1]=='0' || dpRow[0][0] == 0) dpRow[i][j] = 1;
                    else dpRow[i][j] = 0;
                }
                else{
                    if(dpRow[i-1][j]==0 || dpRow[i][j-1]==0) dpRow[i][j] = 1;
                    else dpRow[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < min(2, m); i++){
        for(int j = 0; j < n; j++){
            if(i==0){
                if(j==0){
                    if(col[0]=='0' || row[0]=='0') dpCol[i][j] = 1;
                    else dpCol[i][j] = 0;
                }
                else{
                    if(col[j]=='0' || dpCol[i][j-1]==0) dpCol[i][j] = 1;
                    else dpCol[i][j] = 0; 
                }
            }
            else{
                if(j==0){
                    if(row[1]=='0' || dpCol[0][0] == 0) dpCol[i][j] = 1;
                    else dpCol[i][j] = 0;
                }
                else{
                    if(dpCol[i-1][j]==0 || dpCol[i][j-1]==0) dpCol[i][j] = 1;
                    else dpCol[i][j] = 0;
                }
            }
        }
    }
}

bool win(int x ,int y){
    if(x > 2 && y > 2){
        if(x > y) return win(x-y+2, 2);
        return win(2, y-x+2);
    }
    if(x <= 2) return dpRow[x-1][y-1];
    return dpCol[y-1][x-1];
}

int main(){
    int t, n , m, q, x, y;
    cin  >> t;
    while(t--){
        cin >> row;
        cin >> col;
        n = col.size();
        m = row.size();
        init(n, m);
        fillDP(n ,m);
        cin >> q;
        string res;
        //cout << "diag = " << diag << endl;
        //cout << "zr : ";for(int i:zeroesRow) cout << i << " "; cout << endl;
        //cout << "zc : ";for(int i:zeroesCol) cout << i << " "; cout << endl;
        //cout << "pr : ";for(int i:posRow) cout << i << " "; cout << endl;
        //cout << "pc : ";for(int i:posCol) cout << i << " "; cout << endl;
        /*
        for(auto i: dpRow){
            for(auto j: i) cout << j << " ";
            cout << endl;
        }
        for(auto i: dpCol){
            for(auto j: i) cout << j << " ";
            cout << endl;
        }
        */
        while(q--){
            cin >> x >> y;
            if(win(x, y)) {
                //cout << x <<", " << y << " returned 1\n";
                res.push_back('1');
            }
            else{
                //cout << x <<", " << y << " returned 0\n";
                res.push_back('0');
            }
        }
        cout << res << endl;
    }
}