#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vec;

int count(int e){
    auto l = lower_bound(vec.begin(), vec.end(), e);
    auto r = upper_bound(vec.begin(), vec.end(), e);
    return r-l;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vec.clear();
        vec.resize(n);
        for(int i = 0; i < n; i++) cin >> vec[i];
        sort(vec.begin(), vec.end());
        long long res = 0;
        for(int i = 0; i < n; ){
            int cnt = count(vec[i]);
            for(int e = 1; e <= cnt; e++){
                if(count(e) >= vec[i]) res++;
            }
            int cur = vec[i];
            while(i < n && vec[i]==cur) i++;
        }
        cout << res << endl;
    }
}