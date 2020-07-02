#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> original, required;

int main(){
    int t, n, cnt;
    string s;
    cin >> t;
    while(t--){
        original.clear();
        required.clear();
        cnt = 0;
        cin >> n;
        cin >> s;
        int beg = 0;
        while(beg < n && s[beg]=='#') beg++;
        for(int i = beg; i < n; i++){
            if(s[i] == '.') continue;
            original.push_back(i);
            if(cnt == 0) required.push_back(i);
            else required.push_back(max(required[cnt-1]+2, i));
            cnt++;
        }
        //for(int i: original) cout << i << " "; cout <<endl;
        //for(int i: required) cout << i << " "; cout <<endl;
        long long steps = 0;
        if(cnt > 0 && required[cnt-1] >= n-1) steps = -1;
        else{
            for(int i = 0; i < cnt; i++){
                steps+=(required[i] - original[i]);
                steps+=(required[i]-beg-i);
            }
        }
        cout << steps << endl; 
    }
}