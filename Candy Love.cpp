#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

deque<int> c;
int a, b;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n;
        c.clear();
        a = b = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            c.push_back(temp);
        }
        cin >> x;
        int cur = -1;
        while(!deque.empty()){
            finish(cur, x);
            if(many(x)) box(x);
            else one(x);
        }
    }
}