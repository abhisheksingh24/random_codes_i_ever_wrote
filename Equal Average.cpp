#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        map<int, int> cnt;
        for(int &i: A){
            cin >> i;
            cnt[i]++;
        }
        int div = n / k, rem = n % k;
        vector<int> a, b;
        vector<pair<int, int> > c;
        for(auto p: cnt){
            if(p.second % (div + 1) == 0 && p.second % div == 0){
                c.emplace_back(p.first, p.second);
            }
            else if(p.second % div == 0){
                for(int i = 0; i < p.second / div; i++) a.push_back(p.first);
            }
            else if(p.second % (div + 1) == 0){
                for(int i = 0; i < p.second / (div + 1); i++) b.push_back(p.first);
            }
        }
        //cout << div << " "; for(int i: b) cout << i << " "; cout << "  "; for(int i: a) cout << i << " "; cout << endl;
        while(b.size() < rem && !c.empty()){
            auto p = c.back();
            for(int i = 0; i < p.second / (div + 1) && b.size() < rem; i++){
                b.push_back(p.first);
                c.back().second -= (div + 1);
            }
            if(c.back().second == 0) c.pop_back();
            //cout << c.size() << " " << b.size() << endl;
        }
        //cout << "loop 1" << endl;
        while(!c.empty()){
            auto p = c.back();
            for(int i = 0; i < p.second / div; i++) a.push_back(p.first);
            c.pop_back();
        }
        //cout << "loop 2 " << endl;
        if(b.size() == rem && a.size() + b.size() == k){
            cout << "YES" << endl;
            
            for(int i = 0; i < div; i++){
                for(int j: b) cout << j << " ";
                for(int j: a) cout << j << " ";
            }
            for(int i: b) cout << i << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
    }

}