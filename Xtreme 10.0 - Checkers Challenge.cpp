#include<iostream>

using namespace std;

int checkers[8][8], ways = 0;

bool occupy(int x, int y, int dir){

}

void solve(int x, int y, int blocked, int left, bool king){
    if(x<0 || x>7 || y <0 || y>7) return;
    if(left==0){
        ways++;
        return;
    }
    cout << "@ " << x <<", " << y;
    if(x==0) king = true;
    if(!king){
        cout << " as a normal piece\n";
        if(x>1 && blocked!=1 && checkers[x-1][y]){
            checkers[x-1][y] = 0;
            solve(x-2, y, 3, left-1, king);
            checkers[x-1][y] = 1;
        }
        if(x<6 && blocked!=3 && checkers[x+1][y]){
            checkers[x+1][y] = 0;
            solve(x+2, y, 1, left-1, king);
            checkers[x+1][y] = 1;
        }
        if(y>1 && blocked!=4 && checkers[x][y-1]){
            checkers[x][y-1] = 0;
            solve(x, y-2, 2, left-1, king);
            checkers[x][y-1] = 1;
        }
        if(y<6 && blocked!=2 && checkers[x][y+1]){
            checkers[x][y+1] = 0;
            solve(x, y+2, 4, left-1, king);
            checkers[x][y+1] = 1;
        }
    }
    else{
        cout << "as a king\n";
        if(blocked!=1){
            int i = x-1;
            while(i>0 && !checkers[i][y]) i--;
            checkers[i][y] = 0;
            int temp = i;
            i--;
            while(i>=0 && !checkers[i][y]){
                solve(i, y, 3, left-1, king);
                i--;
            }
            checkers[temp][y] = 1;
        }
        if(blocked!=2){
            int j = y+1;
            while(j<7 && !checkers[x][j]) j++;
            checkers[x][j] = 0;
            int temp = j;
            j++;
            while(j<8 && !checkers[x][j]){
                solve(x, j, 4, left-1, king);
                j++;;
            }
            checkers[x][temp] = 1;
        }
        if(blocked!=3){
            int i = x+1;
            while(i<7 && !checkers[i][y]) i++;
            if(i<7){
                checkers[i][y] = 0;
                int temp = i;
                cout << "Occupied @ " << temp<<endl;
                i++;
                while(i<8 && !checkers[i][y]){
                    cout << "jumping down to "<< i<<endl;
                    solve(i, y, 1, left-1, king);
                    i++;
                }
                checkers[temp][y] = 1;
            }
        }
        if(blocked!=4){
            int j = y-1;
            while(j>0 && !checkers[x][j]) j--;
            checkers[x][j] = 0;
            int temp = j;
            j--;
            while(j>=0 && !checkers[x][j]){
                solve(x, j, 2, left-1, king);
                j--;
            }
            checkers[x][temp] = 1;
        }
    }
}

int main(){
    int t, posX, posY, n, reach;
    char c;
    cin >> t;
    while(t--){
        n = 0; reach = 2;
        for(int i = 0; i < 8; i ++){
            for(int j = 0; j < 8; j++){
                cin >> c;
                if(c=='.') checkers[i][j] = 0;
                else if(c=='x'){
                    checkers[i][j] = 1;
                    n++;
                    //cout << "Piece number " << n << endl;
                }
                else{
                    checkers[i][j] = 0;
                    posX = i;
                    posY = j;
                }
            }
        }
        solve(posX, posY, 0, n, (posX==0));
        cout << ways << endl;
    }
}
