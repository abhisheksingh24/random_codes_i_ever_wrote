#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> ar;

int main(){
    int t, n, temp;
    long long sMin, sMax;
    cin >> t;
    while(t--){
        sMin = sMax = 0;
        ar.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> temp;
            ar.push_back(temp);
        }
        sort(ar.begin(), ar.end());
        for(int i = 0; i < n; i++){
            if(i%2) sMin+=ar[i];
            else sMin-=ar[i];
            if(i<n/2) sMax-=ar[i];
            else sMax+=ar[i];
        }
        cout << sMin << " " << sMax << endl;
    }
}
