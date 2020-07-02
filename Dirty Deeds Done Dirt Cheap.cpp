#include<bits/stdc++.h>

using namespace std;

void printt(vector<int>& a){
    cout << a.size() << endl;
    for(int& i: a) cout << i << " ";
    cout << endl;
}

int main(){
    int n;
    cin >> n; 
    vector<pair<int, int> > A, B;
    map<pair<int, int>, int> id;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a < b) A.emplace_back(b, a);
        else B.emplace_back(b, a);
        id[make_pair(b, a)] = i + 1;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> s1, s2;
    int cur;
    for(int i = A.size() - 1; i >= 0; i--){
        if(s1.empty() || cur > A[i].second){
            s1.push_back(id[A[i]]);
            cur = A[i].first;
        }
    }
    for(int i = 0; i < B.size(); i++){
        if(s2.empty() || cur < B[i].second){
            s2.push_back(id[B[i]]);
            cur = B[i].first;
        }
    }
    if(s1.size() < s2.size()) printt(s2);
    else printt(s1);
}