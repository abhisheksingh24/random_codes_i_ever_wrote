#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int> > flipsHor, flipsVert;
vector<vector<bool> > board;
vector<int> solved;

void fillFlips(int n, int m){
    flipsHor.resize(n);
    //cout << "\thorizontal : \n";
    for(int i = 0; i < n; i++){
        flipsHor[i].resize(m);
        for(int j = 0; j < m; j++){
            if(j==0) flipsHor[i][j] = (board[i][j]==((i+j)%2==0));
            else flipsHor[i][j] = flipsHor[i][j-1] + (board[i][j]==((i+j)%2==0));
        }
    }
    flipsVert.resize(m);
    //cout << "\tvertical : \n";
    for(int i = 0; i < m; i++){
        flipsVert[i].resize(n);
        for(int j = 0; j < n; j++){
            //cout << i << ", " << j << endl;
            if(j==0) flipsVert[i][j] = (board[j][i]==((i+j)%2==0));
            else flipsVert[i][j] = flipsVert[i][j-1] + (board[j][i]==((i+j)%2==0));
        }
    }
}

void solve(int n, int m){
    solved.resize(40001);
    for(int i = 0; i <= 40000; i++) solved[i] = -1;
    solved[0] = 1;
    //cout << "filling flips\n";
    fillFlips(n, m);
    /*cout << "filled flips\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << flipsHor[i][j] << " ";
        }
        cout << endl;
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            cout << flipsVert[j][i] << " ";
        }
        cout << endl;
    }*/

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int flipped = 0;
            bool state = (board[i][j]==((i+j)%2==0));
            for(int s = 2; i+s-1 < n && j+s-1 < m; s++){
                int newFlips = 0, altFlipped, altNewFlips;
                //cout << i << " " << j << " : " << s << endl; 
                newFlips += flipsHor[i+s-1][j+s-2];
                if(j>0) newFlips -= flipsHor[i+s-1][j-1];    
                newFlips += flipsVert[j+s-1][i+s-2];
                if(i>0) newFlips -= flipsVert[j+s-1][i-1];
                newFlips += (board[i+s-1][j+s-1] == ((i+j+2*s-2)%2==0));
                altFlipped = (s-1)*(s-1) - flipped;
                altNewFlips = 2*s - 1 - newFlips;
                int a, b;
                if(!state){
                    a = flipped+newFlips;
                    b = altFlipped+altNewFlips;
                }
                else{
                    a = flipped+altNewFlips;
                    b = altFlipped+newFlips;
                }
                if(a <= b){
                    flipped = a;
                }
                else{
                    flipped = b;
                    state = (!state);
                }
                //cout << i << " " << j << " " << s << " : " << flipped << endl;
                if(solved[flipped] < s) solved[flipped] = s; 
                //cout << "solved\n";
            }
        }
    }

    int cur = solved[0];
    for(int i = 1; i <= 40000; i++){
        if(cur > solved[i]) solved[i] = cur;
        cur = solved[i];
    }
}

int main(){
    int n, m, q, c;
    string inp;
    cin >> n >> m;
    board.resize(n);
    for(int i = 0; i < n; i++){
        board[i].resize(m);
        cin >> inp;
        for(int j = 0; j < m; j++) board[i][j] = (inp[j]=='1');
    }

    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << board[i][j] << " ";
        cout << endl;
    }
    cout<<"solving\n";*/
    solve(n, m);
    cin >> q;
    while(q--){
        cin >> c;
        if(c > 40000) c = 40000;
        cout << solved[c] << endl;
    }
}