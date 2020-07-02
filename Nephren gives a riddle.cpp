#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000000000000

string s1 = "What are you doing while sending \"";
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";
int a = s1.length();
int b = s2.length();
int c = s3.length();

vector<long long> siz(100001);

char solve(long long n, long long k){
    if(n == 0) return f0[k-1];
    if(k <= a) return s1[k-1];
    k-=a;
    if(k <= siz[n-1]) return solve(n-1, k);
    k -= siz[n-1];
    if(k <= b) return s2[k-1];
    k -= b;
    if(k <= siz[n-1]) return solve(n-1, k);
    k -= siz[n-1];
    if(k <= c) return s3[k-1];
    return '.';
}

int main(){
    siz[0] = f0.length();
    for(int i = 1; i <= 100000; i++){
        siz[i] = a + b + c + 2*siz[i-1];
        if(siz[i] > INF) siz[i] = INF;
    }
    //for(int i = 0; i < 10; i++) cout << i << " : " << siz[i] << endl;
    long long n, k, q;
    cin >> q;
    while(q--){
        cin >> n >> k;
        if(siz[n] < k) cout << '.';
        else cout << solve(n, k);
    }
}