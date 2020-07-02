#include<iostream>
#include<vector>

using namespace std;

vector<int> seq;

bool rainbow(int n){
    int counts[8], countsRev[8], curColor = 1, endPos;
    for(int i = 0; i <= 8; i++) counts[i] = countsRev[i] = 0;
    for(int i = 0; curColor <= 6; i++){
        //cout << "color " << curColor << endl;
        if(seq[i]==curColor) counts[curColor]++;
        else if(seq[i]==curColor+1){
            if(counts[curColor]==0) return false;
            curColor++;
            if(curColor==8) return false;
            counts[curColor]++;
        }
        else return false;
        endPos = i;
    }
    while(seq[endPos]==7) endPos++;
    //cout <<"Counts : "; for(int i = 1; i <= 7; i++) cout << counts[i] << " "; cout << endl;
    curColor = 6;
    for(int i = endPos; i < n; i++){
        if(seq[i]==curColor) countsRev[curColor]++;
        else if(seq[i]==curColor-1){
            if(countsRev[curColor]!=counts[curColor]) return false;
            curColor--;
            if(curColor==0) return false;
            countsRev[curColor]++;
        }
        else return false;
    }
    //cout <<"Reverse Counts : "; for(int i = 1; i <= 7; i++) cout << countsRev[i] << " "; cout << endl;
    return counts[1]==countsRev[1];
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        seq.clear();
        seq.resize(n);
        for(int i = 0; i < n; i++) cin >> seq[i];
        if(rainbow(n)) cout << "yes\n";
        else cout << "no\n";
    }
}
