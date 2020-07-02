#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int ar[10000], n;
vector<int> sums;

bool one(int e, int l, int r){
    //cout << "One " << e << " " << l << " " << r << endl;
    if(l>r) return false;
    int m = l + (r-l)/2;
    if(ar[m]==e) return true;
    if(ar[m]<e) return one(e, m+1, r);
    else return one(e, l, m-1);
}

bool two(int s, int l, int r){
    //cout << "Two " << s << " " << l << " " << r << endl;
    if(l>r) return false;
    int m = l + (r-l)/2;
    int minSum = ar[m] + ar[m+1];
    int maxSum = ar[m] + ar[n-1];
    //cout << "Range = " << minSum << " to " << maxSum << endl;
    if(minSum == s || maxSum == s) return true;
    bool a, b;
    if(maxSum < s){
        a = false;
        //cout << "Ignoring left hand side\n";
    }
    else a = two(s, l, m-1);
    if(a) return true;
    if(minSum > s){
        b = false;
        //cout << "Ignoring right hand side\n";
    }
    else b = one(s-ar[m], m+1, n-1) || two(s, m+1, r);
    return b;
}

bool three(int s, int l, int r){
    //cout << "Three " << s << " " <<l << " " << r << endl;
    if(l>r) return false;
    int m = l + (r-l)/2;
    int minSum = ar[m] + ar[m+1] + ar[m+2];
    int maxSum = ar[m] + ar[n-1] + ar[n-2];
    //cout << "Range = " << minSum << " to " << maxSum << endl;
    if(minSum == s || maxSum == s) return true;
    bool a,b;
    if(maxSum < s) {
        //cout << "Ignoring left hand side\n";
        a = false;
    }
    else a = three(s, l, m-1);
    if(a) return true;
    if(minSum > s){
        b = false;
        //cout << "Ignoring right hand side\n";
    }
    else b = two(s-ar[m], m+1, n-2) || three(s, m+1, r);
    return b;
}

int main(){
    int cnt = 0, lim;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    sort(ar, ar+n);
    lim = ar[n-1] + ar[n-2] + ar[n-3];
    for(int s = 6; s <= lim; s++){
        //cout << "Finding " << s << " :\n";
        if(three(s, 0, n-3)) sums.push_back(s);
    }
    cout << sums.size() << endl;
    for(int i : sums) cout << i << " ";
    cout << endl;
}
