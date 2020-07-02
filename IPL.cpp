
#include<iostream>

using namespace std;

int minm[200000];

void init(int a[], int n){
    for(int i = 0; i < n-3; i++){
        minm[i] = -1;
    }
    minm[n-3] = min(min(a[n-3], a[n-2]), a[n-1]);
    minm[n-2] = 0;
    minm[n-1] = 0;
}

int supw(int a[], int n, int start = 0){
    //cout << "supw called @ " << start << endl;
    if(minm[start]==-1){
        //cout << "Finding minimum @ " <<start << endl;
        int x, y, z;
        x = a[start]+supw(a,n,start+1);
        y = a[start+1]+supw(a,n,start+2);
        z = a[start+2]+supw(a,n,start+3);
        minm[start] = min(min(x,y),z);
    }
    //cout << "returning minimum @ " << start << " = " << minm[start] << endl;
    return(minm[start]);
}

int main(){
    int n, a[200000], s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s+=a[i];
    }
    init(a,n);
    s -= supw(a, n);
    cout << s << endl;
}
