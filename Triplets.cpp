#include<iostream>
#include<algorithm>

using namespace std;

static int mod = 1000000007;

void numSum(int B[], int q, int A[], int p, int nx[], int sx[]){
    int num = 0, sum = 0;
    for(int i = 0; i < q; i++){
        while(num<p && A[num]<=B[i]){
            sum=(sum+A[num])%mod;
            num++;
        }
        nx[i] = num;
        sx[i] = sum;
    }
}

int mult(int a, int b, int c = 1, int d =1){
    return((((((a*b)%mod)*c)%mod)*d)%mod);
}

int sum(int a, int b, int c = 0, int d = 0, int e = 0){
    return(((((a+b)%mod+c)%mod+d)%mod+e)%mod);
}

int calc(int B[], int q, int nx[], int nz[], int sx[], int sz[]){
    int m1, m2, m3, m4, res = 0;
    for(int i = 0; i < q; i++){
        m1 = mult(nx[i], sz[i], B[i]);
        m2 = mult(nz[i], sx[i], B[i]);
        m3 = mult(nx[i], nz[i], B[i], B[i]);
        m4 = mult(sx[i], sz[i]);
        res = sum(res, m1, m2, m3, m4);
    }
    return(res);
}



int main(){
    int t, p, q, r, A[100000], B[100000], C[100000], nx[100000], nz[100000], sx[100000], sz[100000];
    cin >> t;
    for(; t; t--){
        cin >> p >> q >> r;
        for(int i = 0 ; i < p; i++) cin >> A[i];
        for(int i = 0 ; i < q; i++) cin >> B[i];
        for(int i = 0 ; i < r; i++) cin >> C[i];
        sort(A, A+p);
        sort(B, B+q);
        sort(C, C+r);
        numSum(B,q,A,p,nx,sx);
        numSum(B,q,C,r,nz,sz);
        cout << calc(B,q,nx,nz,sx,sz) << endl;
    }
}
