#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string a, b;
    vector<int> board;
    cin >> a >> b;
    int l = a.length();
    board.resize(l);
    for(int i = 0; i < l; i++){
        board[i] = 0;
        if(a[i] == '0') board[i]++;
        if(b[i] == '0') board[i]++;
    }
    int placed = 0;
    for(int i = 0; i < l-1; i++){
        if(board[i] == 2){
            if(board[i+1] >= 1){
                board[i]-=2;
                board[i+1]-=1;
                placed++;
            }
        }
        else if (board[i] == 1){
            if(board[i+1] == 2){
                board[i]-=1;
                board[i+1]-=2;
                placed++;
            }
        }
    }
    cout << placed << endl;
}
