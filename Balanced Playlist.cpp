#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), cut(n, -1);
    for(int& i: a) cin >> i;
    multiset<int> active{a[0]};
    int i, j;
    for(i = 0, j = 1; j < n; j++){
        while(i < j){
            int largest = *(--active.end());
            if(largest <= 2 * a[j]) break;
            cut[i] = j;
            active.erase(active.lower_bound(a[i]));
            i++;
        }
        active.insert(a[j]);
    }
    for(j = 0; j < n && i < n; j++){
        while(i < n){
            int largest = *(--active.end());
            if(largest <= 2 * a[j]) break;
            cut[i] = n + j;
            active.erase(active.lower_bound(a[i]));
            i++;
        }
        active.insert(a[j]);   
    }
    for(j = 0; j < n && i < n; j++){
        while(i < n){
            int largest = *(--active.end());
            if(largest <= 2 * a[j]) break;
            cut[i] = 2 * n + j;
            active.erase(active.lower_bound(a[i]));
            i++;
        }
        active.insert(a[j]);   
    }
    for(int i = 0; i < n; i++){
        if(cut[i] == -1) cout << -1 << " ";
        else if(cut[i] > i) cout << cut[i] - i << " ";
        else cout << n - i + cut[i] << " "; 
    }
    cout << endl;
}