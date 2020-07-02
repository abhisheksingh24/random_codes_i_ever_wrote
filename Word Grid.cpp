#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

vector<vector<char> > grid;
vector<string> word;
vector<pair<int, int> > inserted;
vector<vector<vector<char> > > states;

int n;

void init(int n){
    grid.clear();
    grid.resize(4);
    for(int i = 0; i < 4; i++){
        grid[i].resize(4);
        for(int j = 0; j < 4; j++) grid[i][j] = '\0';
    }
    word.clear();
    word.resize(n);
    inserted.clear();
    states.clear();
}

bool possibleRight(int x, string w){
    for(int j = 0; j < 4; j++){
        if(grid[x][j]=='\0') continue;
        if(grid[x][j] != w[j]) return false;
    }
    return true;
}

bool possibleLeft(int x, string w){
    for(int j = 3; j >= 0; j--){
        if(grid[x][j]=='\0') continue;
        if(grid[x][j] != w[3-j]) return false;
    }
    return true;
}

bool possibleBelow(int y, string w){
    for(int i = 0; i < 4; i++){
        if(grid[i][y]=='\0') continue;
        if(grid[i][y] != w[i]) return false;
    }
    return true;
}

bool possibleAbove(int y, string w){
    for(int i = 3; i >= 0; i--){
        if(grid[i][y]=='\0') continue;
        if(grid[i][y] != w[3-i]) return false;
    }
    return true;
}

void placeLeft(int x, string w, vector<pair<int, int> >& ins){
    for(int j = 3; j >= 0; j--){
        if(grid[x][j]=='\0'){
            grid[x][j] = w[3-j];
            pair<int, int> temp;
            temp.first = x;
            temp.second = j;
            ins.push_back(temp);
        }
    }
}

void placeRight(int x, string w, vector<pair<int, int> >& ins){
    for(int j = 0; j < 3; j++){
        if(grid[x][j]=='\0'){
            grid[x][j] = w[j];
            pair<int, int> temp;
            temp.first = x;
            temp.second = j;
            ins.push_back(temp);
        }
    }
}

void placeBelow(int y, string w, vector<pair<int, int> >& ins){
    for(int i = 0; i < 3; i++){
        if(grid[i][y]=='\0'){
            grid[i][y] = w[i];
            pair<int, int> temp;
            temp.first = i;
            temp.second = y;
            ins.push_back(temp);
        }
    }
}

void placeAbove(int y, string w, vector<pair<int, int> >& ins){
    for(int i = 3; i >= 0; i--){
        if(grid[i][y]=='\0'){
            grid[i][y] = w[i];
            pair<int, int> temp;
            temp.first = i;
            temp.second = y;
            ins.push_back(temp);
        }
    }
}

void erase(vector<pair<int, int> > toDelete){
    for(auto p: toDelete){
        grid[p.first][p.second] = '\0';
    }
}

void place(int l, vector<pair<int, int> >& inserted){
    if(l > n){
        states.push_back(grid);
        return;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != 0 && i!=3 && j!= 0 && j!=3) continue;
            if(j==3){
                if(possibleLeft(i, word[l])){
                    vector<pair<int, int> > insertedCur;
                    placeLeft(i, word[l], insertedCur);
                    place(l+1, insertedCur);
                    erase(insertedCur);
                }
            }
            if(j==0){
                if(possibleRight(i, word[l])){
                    vector<pair<int, int> > insertedCur;
                    placeRight(i, word[l], insertedCur);
                    place(l+1, insertedCur);
                    erase(insertedCur);
                }
            }
            if(i==0){
                if(possibleBelow(j, word[l])){
                    vector<pair<int, int> > insertedCur;
                    placeBelow(j, word[l], insertedCur);
                    place(l+1, insertedCur);
                    erase(insertedCur);
                }
            }
            if(i==3){
                if(possibleAbove(j, word[l])){
                    vector<pair<int, int> > insertedCur;
                    placeAbove(j, word[l], insertedCur);
                    place(l+1, insertedCur);
                    erase(insertedCur);
                }
            }
        }
    }
}

int main(){
    int t;
    string temp;
    cin >> t;
    while(t--){
        cin >> n;
        init(n);
        for(int i = 0; i < n; i++) cin >> word[i];
        cout << "solving\n";
        place(0, inserted);
        for(auto g: states){
            for(auto r: g){
                for(auto i: r) cout << i ;
            }
            cout << endl;
        }
    }
}