#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t, a, b, c, d;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        vector<int> sides;
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);
        sides.push_back(d);
        sort(sides.begin(), sides.end());
        if(sides[0] == sides[1] && sides[2] == sides[3]) cout << "YES\n";
        else cout << "NO\n";
    }
}
