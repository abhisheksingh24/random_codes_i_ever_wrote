#include<iostream>
#include<vector>

using namespace std;

void rev(vector<int> &seq, int i, int j){
    if(i >= j) return;
    int temp = seq[i];
    seq[i] = seq[j];
    seq[j] = temp;
    rev(seq, i+1, j-1);
}

int main(){
    int n;
    vector<int> seq;
    cin >> n;
    seq.resize(n);
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
    int steps = 0;
    for(int i = 0; i < n; i++){
        if(seq[i]==i+1) continue;
        for(int j = i+1; j < n; j++){
            if(seq[j]==i+1){
                rev(seq, i, j);
                steps++;
                break;
            }
        }
    }
    cout << steps << endl;
}
