#include<iostream>
#include<limits.h>

using namespace std;

int parent[100001], wealth[100001], maxParentDP[100000];

int maxParent(int i){
    if(parent[i]==-1) return INT_MIN;
    if(maxParentDP[i]==INT_MIN) maxParentDP[i] = max(wealth[parent[i]], maxParent(parent[i]));
    return maxParentDP[i];
}

void init(int n){
    for(int i = 0; i < n; i++){
        maxParentDP[i] = INT_MIN;
    }
}

int main(){
    int n, disparity = INT_MIN;
    cin >> n;
    init(n);
    for(int i = 0; i < n; i++){
        cin >> wealth[i];
    }
    for(int i = 0; i < n; i++){
        cin >> parent[i];
        parent[i]--;
    }
    for(int i = 0; i < n; i++){
        if(parent[i]!=-1) disparity = max(disparity, maxParent(i) - wealth[i]);
    }
    cout << disparity << endl;
}
