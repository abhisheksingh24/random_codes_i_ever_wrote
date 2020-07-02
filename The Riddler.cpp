#include<iostream>

using namespace std;
/*
int  findMultiple(int from, int to, int m){
    //cout << "fm("<<from<<", "<<to<<")\n";
    if(from%m==0) return from;
    int mid = from + (to-from)/2;
    if(mid%m==0) return mid;
    if(mid%m<from%m) return findMultiple(from+1, mid-1, m);
    return(findMultiple(mid+1, to, m));
}
*/

int main(){
    int t, a, b, m, res, r1, r2;
    cin >> t;
    while(t--){
        cin >> a >> b >> m;
        if(a>b){
            a+=b;
            b=a-b;
            a-=b;
        }
        res = (b-a)/m;
        r1 = (b-a)%m;
        r2 = b%m;
        if(r2<=r1) res++;
        cout << res << endl;
    }
}
