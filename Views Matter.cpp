#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    vector<int> stack;
    cin >> n >> m;
    stack.resize(n);
    for(int &i: stack) cin >> i;
    sort(stack.begin(), stack.end());
    long long achieved = 0, removable = 0;
    for(int i = 0; i < n-1; i++) removable += (stack[i] - 1);
    for(int i = 0; i < n-1; i++){
        if(stack[i] > achieved) achieved++;
    }
    removable += achieved;
    if(stack[n-1] == achieved) removable--;
    cout << removable << endl;

}