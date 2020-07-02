#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, k;
    vector<int> vec;
    set<int> maxes;
    cin >> n >> k;
    vec.resize(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    int inserted = 0;
    for(int i = 2000; i >= 1 && inserted < k; i--){
        for(int j = 0; j < n && inserted < k; j++){
            if(vec[j]==i){
                maxes.insert(j);
                inserted++;
            }
        }
    }
    int sum = 0;
    vector<int> res1, res;
    for(auto it: maxes){
        res1.push_back(it);
    }
    for(auto i: res1) sum+=vec[i];
    cout << sum << endl;
    res.resize(k);
    int done = 0;
    for(int i = 0 ; i < k; i++){
        res[i] = res1[i] - done + 1;
        done = res1[i] + 1;
    }
    res[k-1]+=(n-1-res1[k-1]);
    for(int i: res) cout << i << " ";
    cout << endl;
}
