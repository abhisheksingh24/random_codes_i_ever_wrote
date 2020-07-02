#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct sub{
    int l, r;
};

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        int l = s.length();
        vector<sub> same;
        sub cur;
        char curChar = '\0';
        for(int i = 0; i < l; i++){
            if(curChar=='\0'){
                cur.l = i;
                cur.r = i;
                curChar = s[i];
            }
            else if(s[i]==curChar){
                cur.r = i;
            }
            else{
                same.push_back(cur);
                curChar = '\0';
                i--;
            }
        }
        same.push_back(cur);
        long long cnt =0;
        for(sub lr: same){
            long long len = lr.r-lr.l+1;
            cnt+=((len*(len-1))/2);
            if(lr.l >0 && lr.r < l-1 && s[lr.l-1]==s[lr.r+1]) cnt+=1;
        }
        cout << cnt << endl;
    }
}
