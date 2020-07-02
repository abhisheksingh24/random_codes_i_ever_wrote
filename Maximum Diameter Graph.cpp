#include<iostream>
#include<vector>

using namespace std;

vector<int> a;
vector<vector<int> > graph;

int main(){
    int n;
    cin >> n;
    a.resize(n);
    for(int &i: a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    
}