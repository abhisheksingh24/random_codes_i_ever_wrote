#include<iostream>
#include<vector>

#define minfinite -9223372036854775808

using namespace std;

vector <int> a, b;
vector <long long> p, diff;

long long max4(long long a, long long b, long long c, long long d){
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return(max(a,max(b,max(c,d))));
}

long long pref(int i, int n){
    if(i<0) return 0;
    if(i>=n) return(p[n-1]);
    return(p[i]);
}

int main(){
    int n, temp;
    long long curSum = 0, curDiff = minfinite, maxDiff = minfinite, c, d;
    cin >> n;
    vector<long long> diff2(n);
    for(int i = 0; i < n; i++){
       cin >> temp;
       a.push_back(temp);
    }
    for(int i = 0; i  < n; i++){
       cin >> temp;
       b.push_back(temp);
       curSum +=temp;
       p.push_back(curSum);
       curDiff = max(curDiff, a[i]-curSum);
       diff.push_back(curDiff);
    }
    curDiff = minfinite;
    for(int i = n-1; i>=0; i--){
        //cout << "i = "<<i<<endl;
        curDiff = max(curDiff, a[i] - p[i]);
        //cout<<"access to b & p success\n";
        //diff2.insert(diff2.begin()+i, curDiff);
        diff2[i] = curDiff;
        //cout << i << " done\n";
    }

    for(int i = 0; i<n; i++){
        if(i==0) c = minfinite;
        else c = a[i] + p[i-1] + diff[i-1];
        if(i==n-1) d = minfinite;
        else if(i==0) d = a[i] + p[n-1] + diff2[i+1];
        else d = a[i] + p[i-1] + p[n-1] + diff2[i+1];
        maxDiff = max4(maxDiff,a[i],c,d);
    }
    cout << maxDiff << endl;
}
