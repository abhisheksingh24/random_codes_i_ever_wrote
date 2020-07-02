#include<iostream>

using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b,c));
}

int secondMin(int a, int b, int c){
    return(max(min(a,b), min(a,c)));
}

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dis = 0;
    if(n>1) dis += min(a, b);
    if(n>2) dis += min3(a, b, c)*(n-2);
    cout << dis << endl;
}
