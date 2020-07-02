#include<iostream>
#include<vector>
#include<algorithm>

using  namespace std;

int diff(int a, int b){
    int res = a-b;
    if(res < 0) res*=-1;
    return res;
}

int main(){
    int n;
    vector<int> seq;
    cin >> n;
    seq.resize(n/2);
    for(int i = 0; i < n/2; i++) cin >> seq[i];
    sort(seq.begin(), seq.end());
    int evenPos = 2, oddPos = 1, evenCount = 0, oddCount = 0;
    for(int i : seq){
        evenCount += diff(i, evenPos);
        oddCount += diff(i, oddPos);
        evenPos+=2;
        oddPos+=2;
    }
    cout << min(evenCount, oddCount) << endl;
}
