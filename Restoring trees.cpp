#include<bits/stdc++.h>

using namespace std;

bool comp(int& a, int& b){
    return start[a] < start[b];
}

int main(){
    int n;
    cin >> n;
    vector<int> start(n), finish(n);
    for(int& i: start) cin >> i;
    for(int& i: finish) cin >> i;
    vector<int> order;
    for(int i = 0; i < n; i++) order.push_back(i);
    sort(order.begin(), order.end(), comp);
    stack<int> curParent, curFinTym;
    vector<int> parent(n);
    for(int i: order){
        if(curParent.empty()){
            curParent.push(i);
            curFinTym.push(finish[i]);
            parent[i] = 0;
            continue;
        }
        int f = curFinTym.top();
        while(start[i] >= f){
            curParent.pop();
            curFinTym.pop();
            f = curFinTym.top();   
        }
        parent[i] = curParent.top() + 1;
        curParent.push(i);
        curFinTym.push(finish[i]);
    }
    for(int& i: parent) cout << i << " ";
    cout<< endl;
}