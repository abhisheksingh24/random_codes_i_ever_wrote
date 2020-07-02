#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t, n, p, s, cake, diff;
    cin >> t;
    while(t--){
        cake = 0;
        diff = 0;
        cin >> n >> p;
        for(int i = 0; i < n; i++){
            cin >> s;
            if(s>=p/2) cake++;
            else if(s<=p/10) diff++;
        }
        if(cake!=1 || diff!=2) cout << "no\n";
        else cout << "yes\n";
    }
}
