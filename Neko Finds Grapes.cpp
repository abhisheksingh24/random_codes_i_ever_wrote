#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, odd = 0, even = 0;
    cin >> n >> m;
    while(n--){
        int a;
        cin >> a;
        if(a % 2) odd++;
        else even++;
    }
    int res = 0;
    while(m--){
        int b;
        cin >> b;
        if(b % 2){
            if(even-- > 0) res++; 
        }
        else if(odd-- > 0) res++;
    }    
    cout << res << endl;
}