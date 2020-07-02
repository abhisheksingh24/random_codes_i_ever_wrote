#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    sort(a.begin(), a.end());
    bool found = false;
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && a[j] == a[i]) j++;
        if(j - i > 2){
            cout << "cslnb" << endl;
            return 0;
        }
        if(j - i == 2){
            if(found){
                cout << "cslnb" << endl;
                return 0;
            }
            found = true;
        }
        if(i + 2 < n && a[i] + 1 == a[i + 1] && a[i] + 1 == a[i + 2]){
            cout << "cslnb" << endl;
            return 0;
        }
        i = j;
    }
    long long s = 0;
    for(int i = 0; i < n; i++) {
        a[i] -= i;
        s += a[i];
        if(a[i] < 0){
            cout << "cslnb" << endl;
            return 0;
        }
    }
    if(s % 2) cout << "sjfnb" << endl;
    else cout << "cslnb" << endl;
}