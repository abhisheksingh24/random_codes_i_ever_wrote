#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<char> > cross;

bool hor(string name, int x, int y, int n){
    int l = name.length();
    int j = y, cnt = 0;
    while(j < n && cnt < l && name[cnt]==cross[x][j]){
        j++;
        cnt++;
    }
    if(l==cnt) return true;
    j = y; cnt = 0;
    while(j >= 0 && cnt < l && name[cnt]==cross[x][j]){
        j--;
        cnt++;
    }
    return l==cnt;
}

bool vert(string name, int x, int y, int n){
    int l = name.length();
    int i = x, cnt = 0;
    while(i < n && cnt < l &&  name[cnt]==cross[i][y]){
        i++;
        cnt++;
    }
    if(l==cnt) return true;
    i = x; cnt = 0;
    while(i >= 0 && cnt < l &&  name[cnt]==cross[i][y]){
        i--;
        cnt++;
    }
    return l==cnt;
}

bool diag(string name, int x, int y, int n){
    int l = name.length();
    int i = x, j = y, cnt = 0;
    while(i < n && j < n &&  cnt < l && name[cnt]==cross[i][j]){
        i++;
        j++;
        cnt++;
    }
    if(l==cnt) return true;
    i = x; j = y; cnt =0 ;
    while(i >= 0 && j < n &&  cnt < l && name[cnt]==cross[i][j]){
        i--;
        j++;
        cnt++;
    }
    if(l==cnt) return true;
    i = x; j = y; cnt =0 ;
    while(i >= 0 && j >= 0 &&  cnt < l && name[cnt]==cross[i][j]){
        i--;
        j--;
        cnt++;
    }
    if(l==cnt) return true;
    i = x; j = y; cnt =0 ;
    while(i < n && j >= 0 &&  cnt < l && name[cnt]==cross[i][j]){
        i++;
        j--;
        cnt++;
    }
    return l==cnt;
}

bool found(string name, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(hor(name, i, j, n) || vert(name, i, j, n) || diag(name, i, j, n)) return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    cross.resize(n);
    for(int i = 0; i < n; i++){
        cross[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> cross[i][j];
        }
    }
    int m;
    cin >> m;
    string name;
    bool flag;
    for(int i = 0; i < m; i++){
        cin >> name;
        if(!found(name, n)){
            flag = false;
        }
    }
    if(flag) cout << "True\n";
    else cout << "False\n";
}

