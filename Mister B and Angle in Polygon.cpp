#include<iostream>

using namespace std;

int solve(int n, int a){
    for(int m = 1; m <= n-2; m++){
        float curAngle = (m*180/float(n));
        if(curAngle>=a){
            if(curAngle - a <= 90/float(n)) return(m);
            else return(max(1, m-1));
        }
    }
}

int main(){
    int n, a;
    cin >> n >> a;
    int v3 = solve(n,a) + 2;
    cout << "2 1 " << v3<<endl;
}
