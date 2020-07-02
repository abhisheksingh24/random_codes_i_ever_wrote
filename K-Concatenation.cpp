#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long sumAll(vector<int> ar){
    long long res = 0;
    for(int i: ar) res+=i;
    return res;
}

long long maxSumSub(vector<int> ar){
    int n = ar.size();
    long long mxS = 0, curS = 0;
    for(int i: ar){
        curS+=i;
        if(curS < 0) curS = 0;
        if(mxS < curS) mxS = curS;
    }
    return mxS;
}

long long maxSumBeg(vector<int> ar){
    long long mxS = 0, curS = 0;
    for(int i: ar){
        curS+=i;
        if(mxS < curS) mxS = curS;
    }
    return mxS;
}

long long maxSumEnd(vector<int> ar){
    int n = ar.size();
    long long mxS = 0, curS = 0;
    for(int i = n-1; i>=0; i--){
        curS+=ar[i];
        if(mxS < curS) mxS = curS;
    }
    return mxS;
}

int main(){
    int t, n , k;
    cin >> t;
    while(t--){
        vector<int> ar;
        cin >> n >> k;
        ar.resize(n);
        for(int i = 0; i < n; i++) cin >> ar[i];
        long long s = sumAll(ar);
        long long maxAnywhere = maxSumSub(ar);
        long long maxBeg = maxSumBeg(ar);
        long long maxEnd = maxSumEnd(ar);
        if(*min_element(ar.begin(), ar.end()) >= 0) cout << s*k;
        else if(s>=0){
            if(k==1) cout << maxAnywhere;
            else if(k==2) cout << max(maxAnywhere, maxBeg+maxEnd);
            else cout << max(maxAnywhere, maxBeg + s*(k-2) + maxEnd);
        }
        else{
            if(k>=2) cout << max(maxAnywhere, maxBeg + maxEnd);
            else cout << maxAnywhere;
        }
        cout << endl;
    }
}
