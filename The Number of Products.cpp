#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    for(int& i: a) i = (i > 0);
    int neg = 0, pos = 1;
    long long resNeg = 0, resPos = 0;
    int id = 0;
    int tot = 1;
    for(int& i: a){
        if(!i) tot ^= 1;
        if(tot){
            resPos += pos;
            resNeg += neg;
            //resPos++;
            pos++;
        }
        else{
            resPos += neg;
            resNeg += pos;
            //resNeg++;
            neg++;
        }
        //cout << (id++) << " " << resNeg << " " << resPos << endl;
    }
    cout << resNeg << " " << resPos << endl;
}