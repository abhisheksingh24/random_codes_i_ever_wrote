#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<int> seq, subSeq;

int findPos(int num, int l = 0, int r = subSeq.size()-1){
    if(l==r) return l;
    int m = l + (r-l)/2;
    if(seq[m] <= num) r = m;
    else l = m + 1;
    return findPos(num, l, r);
}

int maxLength(int n){
    for(int i = 0; i < n; i++){
        if(subSeq.empty() || seq[i] >= subSeq.back()) subSeq.push_back(seq[i]);
        else subSeq[findPos(seq[i])] = seq[i];
    }
    return subSeq.size();
}

int minMoves(int n){
    return(n-maxLength(n));
}

int main(){
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        seq.push_back(temp);
    }
    cout << minMoves(n) << endl;
}
