#include<iostream>

using namespace std;

int main(){
    int nd, r, xr, n;
    nd = 1023; r = xr = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        char op; int num;
        cin >> op >> num;
        switch(op){
        case '&':
            nd = nd&num;
            break;
        case '|':
            r = r|num;
            break;
        case '^':
            xr = xr^num;
            break;
        }
    }
    cout << 3 << endl;
    cout << "& " << nd << endl;
    cout << "^ "  << xr << endl;
    cout << "| " << r << endl;
}
