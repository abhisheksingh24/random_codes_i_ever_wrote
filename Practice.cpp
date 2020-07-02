#include<bits/stdc++.h>

using namespace std;

int doNothing(const set<int>& s) {
    return 0;
}

int main() {
    set<int> s = {4, 5, 6};
    doNothing({4, 5, 6});
}