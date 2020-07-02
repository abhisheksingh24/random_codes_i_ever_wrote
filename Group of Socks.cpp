#include<iostream>

using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    cout << min3(r, g, b) << endl;
}
