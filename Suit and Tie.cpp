#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

 int main(){
    int n, swaps = 0;
    vector<int> seq;
    cin >> n;
    seq.resize(n*2);
    for(int i = 0; i < n*2; i++) cin >> seq[i];
    for(int i = 0; i < 2*n - 1; i+=2){
        int j = i+1;
        while(seq[j] != seq[i]) j++;
        //cout << i <<  " and " << j << endl;
        for(int k = j; k > i+1; k--){
            swap(seq[k-1], seq[k]);
            //iter_swap(seq.begin() + k-1, seq.end() + k);
            swaps++;
        }
    }
    cout << swaps << endl;
 }
