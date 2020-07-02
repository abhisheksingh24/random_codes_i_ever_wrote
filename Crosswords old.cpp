#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<char> > cross;

bool findHorizontal(string name, int n){
    int l = name.length();
    for(int row = 0; row < n; row++){
        for(int beg = 0; beg <= n-l; beg++){
            int i = beg, j = 0;
            while(i < n && cross[row][i]==name[j]){
                i++;
                j++;
            }
            if(j==l) return true;
        }
    }
    return false;
}

bool findVertical(string name, int n){
    int l = name.length();
    for(int col = 0; col < n; col++){
        for(int beg = 0; beg <= n-l; beg++){
            int i = beg, j = 0;
            while(i < n && cross[i][col]==name[j]){
                i++;
                j++;
            }
            if(j==l) return true;
        }
    }
    return false;
}

bool findDiagonal(string name, int n){
    int l = name.length();
    for(int d = 1; d <= n; d++){
        for(int x = 0; x < d; x++){
            int i = x, j = n-d+x, p = 0;
            while(i < n && j < n && cross[i][j]==name[p]){
                i++;
                j++;
                p++;
            }
            if(p==l) return true;
        }
        for(int x = n-d; x < n; x++){
            int i = x, j = n-x, p = 0;
            while(i < n && j < n && cross[i][j]==name[p]){
                i++;
                j++;
                p++;
            }
            if(p==l) return true;
        }
    }
    return false;
}

bool found(string name, int n){
    if(findHorizontal(name, n) || findVertical(name, n) || findDiagonal(name, n)) return true;
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
            break;
        }
    }
    if(flag) cout << "True\n";
    else cout << "False\n";
}
