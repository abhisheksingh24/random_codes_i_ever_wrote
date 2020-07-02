#include<iostream>
#include<string>

using namespace std;

short int res[6100][6100];

void init(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            res[i][j] = 0;
        }
        res[i][i] = 1;
    }
}

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

void fillRes(string s, int l){
    for(int i = 0, j = 1; j < l; i++, j++){
        if(s[i] == s[j]) res[i][j] = 2;
        else res[i][j] = 1;
    }
    for(int k = 3; k <= l; k++){
        for(int i = 0, j = k-1; j < l; i++, j++){
            int temp;
            if(s[i] == s[j]) temp = 2;
            else temp = 0;
            res[i][j] = max3(temp+res[i+1][j-1], res[i+1][j], res[i][j-1]);
        }
    }
}

int maxLen(string s, int l){
    fillRes(s,l);
    return (l - res[0][l-1]);
}

int main(){
    int t, l;
    string s;
    init(6100);
    cin >> t;
    while(t--){
        cin >> s;
        l = s.length();
        cout << maxLen(s,l) << endl;
    }
}
