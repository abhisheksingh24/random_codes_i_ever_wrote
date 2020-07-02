#include<bits/stdc++.h>

using namespace std;

vector<bool> c, a;
vector<int> onlyC, onlyA, both, none;

int main(){
    int n;
    cin >> n;
    c.resize(n);
    a.resize(n);
    string inp;
    cin >> inp;
    for(char i: inp) c.push_back(i == '1');
    cin >> inp;
    for(char i: inp) a.push_back(i == '1');
    for(int i = 0; i < n; i++){
        if(a[i] && c[i]) both.push_back(i+1);
        else if(a[i]) onlyA.push_back(i+1);
        else if(c[i]) onlyC.push_back(i+1);
        else none.push_back(i+1);
    }
    if(onlyA.size()> n/2 || onlyC.size() > n/2) cout << -1 << endl;
    else{
        vector<int> res;
        int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
        while(i1 < onlyA.size() && i2 < onlyC.size()){
            res.push_back(onlyC[i1]);
            i1++; i2++;
        }
        while(i2 < onlyC.size() && i3 < both.size()){
            res.push_back(both[i3]);
            i2++; i3++;
        }
        while(i1 < onlyA.size() && i3 < both.size()){
            res.push_back(onlyA[i1]);
            i1++; i3++;
        }
        while(i2 < onlyC.size() && i4 < none.size()){
            res.push_back(onlyC[i2]);
            i2++; i4++;
        }
        while(i1 < onlyC.size() && i4 < none.size()){
            res.push_back(none[i4]);
            i1++; i4++;
        }
        if((both.size() - i3) % 2){
            cout << -1 << endl;
            return 0;
        }
        while(i3 < both.size()){
            res.push_back(both[i3]);
            i3+=2;
        }
        while(i4 < none.size()){
            res.push_back(none[i4]);
            i4+=2;
        }
        for(int i: res) cout << i + 1 << " ";
        cout << endl;
    }
}