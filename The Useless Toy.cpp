#include<iostream>
#include<string>

using namespace std;

int moves(char bp, char ep, int step){
    char seq[7] = {'v', '<', '^', '>', 'v', '<', '^'};
    int l, r;
    if(step==1) l = 0;
    else l = 6;
    while(seq[l] != bp) l+=step;
    for(r = l; seq[r] != ep; r+=step);
    return (r-l)*step;
}

string direction(char bp, char ep, int n){
    int cwMoves, acwMoves;
    cwMoves = moves(bp, ep, 1);
    acwMoves = moves(bp, ep, -1);
    if(cwMoves == acwMoves) return "undefined";
    else if(cwMoves == n) return "cw";
    else return "ccw";
}

int main(){
    char begPos, endPos;
    cin >> begPos >> endPos;
    int n;
    cin >> n;
    n = n % 4;
    cout << direction(begPos, endPos, n) << endl;
}
