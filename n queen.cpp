#include<bits/stdc++.h>

using namespace std;

class Queen{ 
    pair<int, int> pos;

  public:

    pair<int, int> position(){
        //get position of current queen
        return pos;
    }
    
    void place(int x, int y){
        //place current queen in desired location
        pos.first = x;
        pos.second = y;
    }

    bool canMoveTo(int x, int y){
        //function to check if square(x, y) can be attacked by this queen
        if(x == pos.first) return true; // same row
        if(y == pos.second) return true; // same collumn
        if(x - y == pos.first - pos.second) return true; // same
        if(x + y == pos.first + pos.second) return true; // diagonal
        return false;
    }

};

class Board{
    int n;
    vector<vector<int> > state; // 2d matrix for state
    //we store 0 if cell is empty and 1 if it contains a queen
    vector<Queen> queens; // a list of queens on board currently

  public:
    Board(int sz){
        n = sz;
        state.resize(n, vector<int>(n, 0)); // resize to n*n
    }

    void displayBoard(){
        //representing queens by Q and empty cells by .
        for(auto row: state){
            for(int cell: row){
                if(cell) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
    }

    void placeQueen(Queen& q, int x, int y){
        state[x][y] = 1;
        q.place(x, y);
        queens.push_back(q);
    }

    void liftQueen(Queen& q, int x, int y){
        state[x][y] = 0;
        // search for the queen to be deleted in the list of queens and pop it
        for(auto it = queens.begin(); it != queens.end(); ++it){
            if(it -> position() == make_pair(x, y)){
                queens.erase(it);
                break;
            }
        }
        q.place(-1, -1);
    }

    bool underAttack(int x, int y){
        //check if (x, y) is under attack by any queen on board
        for(auto q: queens){
            if(q.canMoveTo(x, y)) return true;
        }
        return false;
    }

    bool placeAllQueens(Queen& q, int col){
        //main function. places all queens on board
        if(col >= n) return true;
        for(int row = 0; row < n; row++){
            if(!underAttack(row, col)){
                placeQueen(q, row, col);
                Queen newQueen;
                if(placeAllQueens(newQueen, col + 1)) return true;
                liftQueen(q, row, col);
            }
        }
        return false;
    }
};

void doEightQueens(){
    Board b(8);
    Queen q;
    if(b.placeAllQueens(q, 0)) b.displayBoard();
    else cout << "Not possible\n";
}

int main(){
    doEightQueens();
}