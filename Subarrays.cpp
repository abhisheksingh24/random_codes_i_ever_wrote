#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> a;
 
void init(int n){
    a.resize(n);
}
 
int main(){
    int n;
    cin >> n;
    init(n);
    for(int& i: a) cin >> i;
    int beg = 0;
    while(beg < n && a[beg] < 0) beg++;
    long long s = 0, k = 0, x = 0, x2 = 0;
    for(int i = beg; i < n; i++){
        //cout << i << " : " << s << ", " << k << ", " << x << ", " << x2 << endl;
        x += a[i], x2 += a[i];
        if(k == 0){
            s = x, ++k, x = x2 = 0;
            continue;
        }
        long long num1 = s+x, num2 = s+x2;
        double s1 = num1/(double)k;
        double s2 = num2/(double)(k+1);
        double s3 = x2;
        bool increased = 0;
        if(s3 > (double)s/k) s = s3, k = 1, x2 = x = 0;
        if(s1 > (double)s/k) s = num1, x = x2 = 0;
        if(s2 >= (double)s/k) s = num2, ++k, x2 = x = 0;
        x2 = max((long long)0, x2);
    }
    if(k == 0) cout << "0 0\n";
    else cout << s/k << " " << k << endl;
}