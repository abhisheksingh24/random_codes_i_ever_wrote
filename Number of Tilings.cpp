#include<iostream>

using namespace std;

#define mod 10000

int n, res[1000001], res2[1000001];

void init(){
    for(int i = 0; i<n+1; i++) res[i] = res2[i] = -1;
}

int trapez(int);

int rect(int length){
    //cout << "length = "<<length<<endl;
    if(length<0) return 0;
    if(length == 0) return 1;
    if(res[length]==-1) res[length] = (rect(length-1)%mod + rect(length-2)%mod + (2*trapez(length-2))%mod)%mod;
    return(res[length]);
}

int trapez(int smallSide){
    if(smallSide<=0) return 0;
    if(res2[smallSide] == -1) res2[smallSide] = rect(smallSide-1)+trapez(smallSide-1);
    return(res2[smallSide]);
}


int main(){
    cin >> n;
    init();
    res[0] = 0;
    for(int i = 1; i <= n; i++){
        res[i] = rect(i);
        res2[i] = trapez(i);
    }
    if(res[n] < 1000) cout<<0;
    cout << res[n] << endl;
}
