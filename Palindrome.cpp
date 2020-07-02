#include<iostream>
#include<string>

using namespace std;

short int res[3][5000];
string s;

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

int maxLen(short int ar1[], short int ar2[], short int ar3[], int n, int l){
    //cout << "maxLen : n = "<<n<<", l = "<< l<<endl;
    for(int i = 0, j = n-1; j < l; i++, j++){
        int temp = (s[i]==s[j] ? 2 : 0);
        ar3[i] = max3(ar2[i], ar2[i+1], temp + ar1[i+1]);
    }
    if(n==l){
        //cout << "n = "<<n<<" : "<<ar3[0]<<endl;
        return ar3[0];
    }
    //cout << "next function called with n = "<<n+1<<endl;
    return maxLen(ar2, ar3, ar1, n+1, l);
}

int solve(int l){
    if(l==1) return 0;
    if(l==2) return (s[0]==s[1] ? 0 : 1);
    for(int i = 0; i < l; i++) res[0][i] = 1;
    for(int i = 0; i < l-1; i++) res[1][i] = (s[i]==s[i+1] ? 2 : 1);
    short int len = maxLen(res[0], res[1], res[2], 3, l);
    return l-len;
}

int main(){
    int l;
    cin >> l;
    cin >> s;
    cout << solve(l) << endl;
}
