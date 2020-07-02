#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int& i: A) cin >> i;
    multiset<int> mn;
    mn.insert(A[0]);
    for(int i = 1; i < n; i++){
        auto it = mn.lower_bound(A[i]);
        if(it == mn.begin()) mn.insert(A[i]);
        else{
            mn.erase(--it);
            mn.insert(A[i]);
        }
    }
    cout << mn.size() << endl;
}