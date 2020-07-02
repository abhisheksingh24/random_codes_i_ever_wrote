#include<iostream>
#include<vector>

using namespace std;

int firstDig(long long n){
    while(n >= 10) n/=10;
    return n;
}

long long power(long long base, long long exp){
    if(exp == 0) return 1;
    if(exp%2) return base*power(base*base, exp/2);
    return power(base*base, exp/2);
}

int numDig(long long n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n/=10;
    }
    return cnt;
}


long long largest(int n){
    int beg = 0;
    while(n--) beg = beg*10 + 9;
    return beg;
}

long long next(long long n){
    int d = numDig(n);
    int f = firstDig(n);
    return (f-1)*power(10, d-1) + largest(d-1);
}


long long findK(long long n){
    if(n == 0) return 1;
    int m = firstDig(n);
    long long nxt = next(n);
    long long times = (n - nxt + m - 1)/m;
    cout << times << " to " <<  n - times*m << endl;
    return times + findK(n - times*m);
}

int main(){
    cout << numDig(21421) << endl;
    cout << largest(3) << endl;
    cout << firstDig(782194) << endl;
    cout << findK(170);

    int n = 170, cnt = 0;
    while(n>0){
        n -= firstDig(n);
        cout << ++cnt << " : " << n << endl;
    }
    /*
    int t, k;
    cin >> t;
    while(t--){
        cin >> k;

    }
    */
}