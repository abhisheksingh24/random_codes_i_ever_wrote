#include<iostream>
#include<limits>

using namespace std;

int diff(int a, int b){
    int res = a-b;
    if(res < 0) res*=-1;
    return res;
}

int main(){
    int t, n, x, y, d, a, b, c;
    cin >> t;
    while(t--){
        a = b = c = numeric_limits<int>::max(); 
        cin >> n >> x >> y >> d;
        if(diff(y, x) % d == 0) a = diff(y, x)/d;
        if((y-1) % d == 0) b = (x+d-2)/d + (y-1)/d;
        if((n-y) % d == 0) c = (n-x+d-1)/d + (n-y)/d;
        int res = min(a, min(b, c));
        if(res == numeric_limits<int>::max()) res = -1;
        cout <<  res << endl;
    }
}