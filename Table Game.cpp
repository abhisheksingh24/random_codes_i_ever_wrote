#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string row, col;
vector<int> zeroesRow, zeroesCol, posRow, posCol;
bool diag;

bool precompute(int n, int m){
    zeroesRow.push_back(0);
    zeroesCol.push_back(0);
    posRow.push_back(0);
    posCol.push_back(0);
    for(int i = 0; i < n; i++){
        if(col[i]=='0') zeroesCol.push_back(i+1);
        if(i < n-1 && col[i]=='0' && col[i+1]=='1') posCol.push_back(i);
    }
    for(int i = 0; i < m; i++){
        if(row[i]=='0') zeroesRow.push_back(i+1);
        if(i < m-1 && row[i]=='0' && row[i+1]=='1') posRow.push_back(i);
    }
    if(n==1 || m==1) return row[0]=='0' || col[0]=='0';
    bool a = col[1]-'0', b = col[0]-'0', c = row[0]-'0', d = row[1]-'0';
    //return ((a&b&(!c))|(a&(!b)&c)|((!b)&c&d)|(b&(!c)&d));
    //return ((a&(!c))|(a&(!b))|((!a)&(!b)&(!c))|((!b)&d)|((!c)&d));
    return (((!b)|(!c))&(a|d));
}

bool rowWise(int i){
    //cout << "rowWise : " << i << endl;
    vector<int>::iterator it = upper_bound(posRow.begin(), posRow.end(), i);
    //cout << "it = " << (*it) << endl;
    --it;
    //cout << "it = " << (*it) << endl;
    if((*it) == 0){
        //cout << "it = 0\n";
        if(i%2) return (!diag);
        return diag;
    }
    return(((i - (*it)) % 2) == 0);
}

bool columnWise(int i){
    vector<int>::iterator it = upper_bound(posCol.begin(), posCol.end(), i);
    --it;
    if((*it) == 0){
        if(i%2) return (!diag);
        return diag;
    }
    return(((i - (*it)) % 2) == 0);
}

bool win(int x, int y){
    //cout << "calculating for " << x << ", " << y << endl;
    if(x==1){
        vector<int>::iterator it = upper_bound(zeroesRow.begin(), zeroesRow.end(), y);
        --it;
        if((*it) == 0){
            if(y%2) return col[0]=='0';
            else return col[0]=='1';
        }
        return (y-(*it))%2==0;
    }
    if(y==1){
        vector<int>::iterator it = upper_bound(zeroesCol.begin(), zeroesCol.end(), x);
        --it;
        if((*it) == 0){
            if(x%2) return row[0]=='0';
            else return row[0]=='1';
        }
        return (x-(*it))%2==0;
    }
    if(x==y) return diag;
    if(x < y) return rowWise(y-x);
    return columnWise(x-y);
}

int main(){
    int t, n , m, q, x, y;
    cin  >> t;
    while(t--){
        cin >> row;
        cin >> col;
        n = col.size();
        m = row.size();
        diag = precompute(n, m);
        cin >> q;
        string res;
        //cout << "diag = " << diag << endl;
        //cout << "zr : ";for(int i:zeroesRow) cout << i << " "; cout << endl;
        //cout << "zc : ";for(int i:zeroesCol) cout << i << " "; cout << endl;
        //cout << "pr : ";for(int i:posRow) cout << i << " "; cout << endl;
        //cout << "pc : ";for(int i:posCol) cout << i << " "; cout << endl;
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
