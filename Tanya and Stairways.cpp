#include<iostream>
#include<vector>

using namespace std;

 int main(){
    int n;
    vector<int> counting, steps;
    cin >> n;
    counting.resize(n);
    for(int i = 0; i < n; i++) cin >> counting[i];
    for(int i = 1; i < n; i++){
        if(counting[i]==1) steps.push_back(counting[i-1]);
    }
    steps.push_back(counting[n-1]);
    cout << steps.size() << endl;
    for(int i: steps) cout << i << " ";
    cout << endl;
 }

