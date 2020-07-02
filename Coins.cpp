#include<iostream>

using namespace std;

int solve(int s, int n){
    if(s==0) return 0;
    if(s <= n) return 1;
    return s/n + solve(s%n, n);
}

int main(){
    int n, s;
    cin >> n >> s;
    cout << solve(s, n) << endl;
}