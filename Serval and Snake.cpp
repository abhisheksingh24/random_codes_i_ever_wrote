#include<bits/stdc++.h>

using namespace std;

bool query(int a, int b, int c, int d){
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    cout.flush();
    int rep;
    cin >> rep;
    return (rep % 2);
}

pair<int, int> tryFindRows(int n){
    int found = 0;
    pair<int, int> res = make_pair(-1, -1);
    for(int r = 1; r < n; ++r){
        if(query(r, 1, r, n)){
            if(found == 0){
                res.first = r;
                found++;
            }
            else{
                res.second = r;
                return res;
            }
        }
    }
    if(res.first == -1) return res;
    res.second = n;
    return res;
}

pair<int, int> tryFindCols(int n){
    int found = 0;
    pair<int, int> res = make_pair(-1, -1);
    for(int c = 1; c < n; ++c){
        if(query(1, c, n, c)){
            if(found == 0){
                res.first = c;
                found++;
            }
            else{
                res.second = c;
                return res;
            }
        }
    }
    res.second = n;
    return res;
}

int isolateRowFromCol(int col, int n){
    int u = 1, d = n;
    while(u <= d){
        if(u == d) return u;
        int m = u + (d - u)/2;
        if(query(u, col, m, col)) d = m;
        else u = m + 1;
    } 
    return -1;
}

int isolateColFromRow(int row, int n){
    int l = 1, r = n;
    while(l <= r){
        if(l == r) return l;
        int m = l + (r - l)/2;
        if(query(row, l, row, m)) r = m;
        else l = m + 1;
    } 
    return -1;
}

int main(){
    int n;
    cin >> n;
    pair<int, int> r = tryFindRows(n);
    if(r.first == -1){
        pair<int, int> c;
        c = tryFindCols(n);
        int r1 = isolateRowFromCol(c.first, n);
        int r2 = isolateRowFromCol(c.second, n);
        cout << "! " << r1 << " " << c.first<< " " << r2 << " " << c.second << endl;
        return 0; 
    }
    else{
        int c1 = isolateColFromRow(r.first, n);
        int c2 = isolateColFromRow(r.second, n);
        cout << "! " << r.first << " " << c1 << " " << r.second << " " << c2 << endl;
        return 0; 
    }
}