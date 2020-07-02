#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > A(n);
    for(int i = 0; i < n; i++){
        A[i].second = i + 1;
        cin >> A[i].first; 
    }
    sort(++A.begin(), A.end());
    int tot = 0;
    for(auto p: A) tot += p.first;
    int maj = tot / 2 + 1;
    int seats = A[0].first;
    vector<int> parties = {1};
    for(int i = 1; i < n && seats < maj && 2 * A[i].first <= A[0].first; i++) {
        seats += A[i].first;
        parties.push_back(A[i].second);
    }
    if(seats < maj) cout << 0 << endl;
    else{
        cout << parties.size() << endl;
        for(int i: parties) cout << i << " ";
        cout << endl;
    }
}