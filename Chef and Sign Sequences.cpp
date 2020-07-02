#include<iostream>
#include<string>

using namespace std;

int minP(string s, int l){
    int cnt = 1, maxCount = 1;
    char sign = '=';
    for(int i = 0; i < l; i++){
        if(s[i] != '='){
            if(sign=='='){
                sign = s[i];
                cnt = 2;
            }
            else if(s[i]==sign){
                cnt++;
            }
            else{
                sign = s[i];
                cnt = 2;
            }
        }
        if(cnt > maxCount) maxCount = cnt;
    }
    return maxCount;
}

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        cout << minP(s, s.length()) << endl;
    }
}
