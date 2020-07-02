#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> sheet(n);
        for(string& s: sheet) cin >> s;
        vector<set<int> > row(26), col(26);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(sheet[i][j] == '.') continue;
                row[sheet[i][j] - 'a'].insert(i);
                col[sheet[i][j] - 'a'].insert(j);
            }
        }
        bool impossible = false;
        for(int i = 0; i < 26; i++){
            if(row[i].size() > 1 && col[i].size() > 1){
                impossible = true;
            }
        }
        if(impossible){
            cout << "NO" << endl;
            continue;
        }
        vector<int> beg(26, -1), endd(26, -1);
        int lst = -1;
        for(int i = 0; i < 26; i++){
            if(row[i].size() == 1){
                int r = *row[i].begin();
                beg[i] = 0;
                while(sheet[r][beg[i]] != 'a' + i) beg[i]++;
                endd[i] = beg[i];
                while(endd[i] < m && (sheet[r][endd[i]] == 'a' + i || (sheet[r][endd[i]] != '.' && sheet[r][endd[i]] > 'a' + i))) endd[i]++;
                for(int j = endd[i]; j < m; j++){
                    if(sheet[r][j] == 'a' + i){
                        impossible = true;
                        break;
                    }
                }
                lst = i;
            }
            else if(col[i].size() == 1){
                int c = *col[i].begin();
                beg[i] = 0;
                while(sheet[beg[i]][c] != 'a' + i) beg[i]++;
                endd[i] = beg[i];
                while(endd[i] < n && (sheet[endd[i]][c] == 'a' + i || (sheet[endd[i]][c] != '.' && sheet[endd[i]][c] > 'a' + i))) endd[i]++;
                for(int j = endd[i]; j < n; j++){
                    if(sheet[j][c] == 'a' + i){
                        impossible = true;
                        break;
                    }
                }
                lst = i;
            }
        }
        if(impossible){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << lst + 1 << endl;
        for(int i = 0; i <= lst; i++){
            if(beg[i] != -1){
                if(row[i].size() == 1){
                    int r = *row[i].begin();
                    cout << r + 1 << " " << beg[i] + 1 << " " << r + 1 << " " << endd[i] << endl;
                }
                else{
                    int c = *col[i].begin();
                    cout << beg[i] + 1 << " " << c + 1 << " " << endd[i] << " " << c + 1 << endl;
                }
            }
            else{
                if(row[lst].size() == 1){
                    int r = *row[lst].begin();
                    cout << r + 1 << " " << beg[lst] + 1 << " " << r + 1 << " " << endd[lst] << endl;
                }
                else{
                    int c = *col[lst].begin();
                    cout << beg[lst] + 1 << " " << c + 1 << " " << endd[lst] << " " << c + 1 << endl;
                }
            }
        }
    }
}