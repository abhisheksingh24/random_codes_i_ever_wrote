#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool isPR(int n){
    vector<int> dig;
    for(int temp = n; temp > 0; temp/=10) dig.push_back(temp%10);
    for(int d: dig) if(d == 2 || d == 3 || d == 5 || d == 7) if(n%d) return false;
    for(int i = 0; i < dig.size() - 1; i++){
        if(gcd(dig[i], dig[i+1]) == 1) return false;
    }
}

int main(){
    int cnt = 0;
    for(int i = 1; i < 1000000;i++){
        if(isPR(i)) cnt++;
    }
    cout << cnt;
}