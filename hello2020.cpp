#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sa(n), sb(n), ea(n), eb(n);
    for (int i = 0; i < n; i++) {
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    map<int, vector<int>> ent1, ext1, ent2, ext2;
    set<int> check;
    for (int i = 0; i < n; i++) {
        ent1[sa[i]].push_back(i);
        ent2[sb[i]].push_back(i);
        check.insert(sa[i]);
        check.insert(ea[i]);
        check.insert(sb[i]);
        check.insert(eb[i]);
        ext1[ea[i]].push_back(i);
        ext2[eb[i]].push_back(i);
    }
    vector<int> o1, o2, eno1(n), exo1(n), eno2(n), exo2(n);
    for (int t: check) {
        for (int i: ent1[t]) o1.push_back(i);
        for (int i: ext1[t]) o1.push_back(i);
        for (int i: ent2[t]) o2.push_back(i);
        for (int i: ext2[t]) o2.push_back(i);
    }
    for (int i = 0; i < o1.size(); i++) exo1[o1[i]] = i, exo2[o2[i]] = i;
    for (int i = (int)o1.size() - 1; i >= 0; i--) eno1[o1[i]] = i, eno2[o2[i]] = i;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (exo1[i] - eno1[i] != exo2[i] - eno2[i]){
            flag = false;
            break;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}