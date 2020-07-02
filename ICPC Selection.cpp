#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

map<string, vector<string> > clg;

int main(){
    int t, n, m, k;
    vector<string> emp;
    string h, c;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        while(n--){
            cin >> h >> c;
            clg[c].push_back(h);
        }
        for(auto a:clg){
            cout << a.first << " : ";
            for(auto b: a.second)cout << b << ", ";
            cout << endl;
        }
    }
}
