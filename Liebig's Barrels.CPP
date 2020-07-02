#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> heights;
    int n, k, l;
    cin >> n >> k >> l;
    heights.resize(n*k);
    for(int i = 0; i < n*k; i++) cin >> heights[i];
    sort(heights.begin(), heights.end());
    int lim = 0;
    long long vol = 0;
    while(lim < n && heights[lim+1]-heights[0] <= l) lim++;
    if(lim < n-1) cout << 0 << endl;
    else{
        int x = n*k - k;
        while(lim < x){
            vol+=heights[lim];
            lim--;
            x-=k;
        }
        while(x >= 0){
            vol+=heights[x];
            x-=k;
        }
        cout << vol << endl;
    }
}
