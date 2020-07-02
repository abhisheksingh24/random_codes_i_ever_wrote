#include<iostream>
#include<set>

using namespace std;
#define ms multiset<int>
int main(){
    ms sizes;
    int m, x, y, height = 0;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        cin >> y;
        sizes.insert(min(x,y));
    }
    for(ms::iterator i = sizes.begin(); i!=sizes.end(); i++){
        if(*i > height) height++;
    }
    cout << height <<endl;
    return 0;
}
