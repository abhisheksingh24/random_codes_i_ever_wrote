#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

double isValid(int x, int y){
    long long sq1 = (long long)(x)*(long long)(x);
    long long sq2 = (long long)(y)*(long long)(y);
    double res = sqrt(sq1 + sq2);
    if(res >= 1500000) return false;
    return (res <= 1000000);
}

 int main(){
    int n, x=0, y=0, tx, ty;
    vector<int> response;
    cin >> n;
    response.resize(n);
    for(int i = 0; i < n; i++){
        cin >> tx >> ty;
        if(isValid(x+tx, y+ty)){
            x+=tx;
            y+=ty;
            response[i] = 1;
        }
        else{
            x-=tx;
            y-=ty;
            response[i] = -1;
        }
    }
    for(int i = 0; i < n; i++) cout << response[i] << " ";
    cout << endl;
 }
