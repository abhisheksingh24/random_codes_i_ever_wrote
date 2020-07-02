#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

#define LIM 4294967295

vector<int> getArray(int n){
    vector<int> res;
    int a = 1;
    float d = ((2.0*(LIM - n)) / n) / (n-1);
    //cout << "d = " << d <<endl;
    for(int i = 0; i < n; i++){
        res.push_back((int)(a + i*d));
    }
    return res;
}

/*
long long sum(vector<int> ar){
    long long s = 0;
    for(int i: ar){
        s+=i;
    }
    return s;
}
*/

int main(){
    vector<int> a;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        a = getArray(n);
        for(int i : a) cout << i << " ";
        //cout << a[n-1] << "\tSum = " << sum(a);
        cout << endl;
    }

}
