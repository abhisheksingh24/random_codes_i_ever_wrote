#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int T, n, t, x, y, z, num, den, g;
    cin >> T;
    while(T--){
        cin >> n >> t >> x >> y >> z;
        if(t == 2 || t == 4){
            num = 2*n - 2*y + 1;
        }
        else if(t == 1){
            if(x < y && y < z) num = 2*n - y;
            else if(x > y && y > z) num = 2*n - y + 2;
            else if(x < y) num = y-1;
            else num = y+1;
        }
        else{
            if(x < y && y < z) num = 2*n - y + 2;
            else if(x > y && y > z) num = 2*n - y;
            else if(x < y) num = y-1;
            else num = y+1;
        }

        den = 2*n + 1;
        g = gcd(num, den);
        num/=g; den/=g;
        cout << num << " " << den << endl;
    }
}