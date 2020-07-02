#include<iostream>
#include<algorithm>

using namespace std;

int a[10000], n;

int search(int i){
    if(i>0 && a[i-1]==a[i]) return 1;
    int s, l = i, r = i+1, e = 2*a[i];
    while(l>=0 && r<n){
        s = a[l] + a[r];
        if(s==e) return 1;
        else if(s<e) r++;
        else l--;
    }
    return 0;
}

int main(){
    int count=0;
    cin >> n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
    for(int i = 0; i < n; i++){
        count+=search(i);
    }
    cout << count <<endl;
}
