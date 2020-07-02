#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isPresent[123];

void init(){
    for(int i = 'a'; i <= 'z'; i++) isPresent[i] = false;
}

int numChars(string str){
    for(int c : str){
        isPresent[c] = true;
    }
    int res = 0;
    for(int i = 'a'; i <= 'z'; i++){
        if(isPresent[i]) res++;
    }
    return res;
}

vector<int> fillLengths(string str){
    vector<int> len;
    len.clear();
    char cur = str[0];
    int curLen = 0;
    for(char c : str){
        if(c==cur) curLen++;
        else{
            len.push_back(curLen);
            cur = c;
            curLen = 1;
        }
    }
    len.push_back(curLen);
    return len;
}

bool similar(vector<int> a, vector<int> b){
    int s1 = a.size(), s2 = b.size();
    if(s1 != s2) return false;
    for(int i = 0; i < s1; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main(){
    int t;
    string p, q;
    vector<int> len1, len2;
    cin >> t;
    while(t--){
        cin >> p >> q;
        if(numChars(p)==26){
            if(p.compare(q)==0) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            len1 = fillLengths(p);
            len2 = fillLengths(q);
            if(similar(len1, len2)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
