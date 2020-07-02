#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, k;
    vector<int> ar;
    set<int> found;
    cin >> n >> k;
    ar.resize(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    found.insert(0);
    for(int z = 0; z < k; z++){
        set<int> toPush;
        for(int a: ar){
            //cout<<"a= "<<a<<endl;
            for(int b: found){
                //cout<<"b= "<<b<<" or = " << (a | b) << endl;
                toPush.insert(a | b);
            }
            //for(int i: toPush) cout << i << " "; cout << endl;
        }
        for(int p: toPush) found.insert(p);
    }
    cout << found.size() - 1 << endl;
}
