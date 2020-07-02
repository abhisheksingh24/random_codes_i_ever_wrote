#include<iostream>

using namespace std;

int diff(int x, int y, int k, int s[]){
    int r1, r2, a, b;
    a = max(s[x], s[y]);
    b = min(s[x], s[y]);
    r1 = a - b;
    r2 = b + k - a;
    return(min(r1, r2));
}

int main(){
    int n, k, q, s[100000], num, x, y, c;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> num;
        for(int j = 0; j < num; j++){
            cin >> c;
            s[c] = i;
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        cout << diff(x, y, k, s) << endl;
    }
    return 0;
}
