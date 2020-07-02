#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int numFact(int n){
    int res = 0;
    while(n%2==0){
        n/=2;
        res++;
    }
    int s = sqrt(n);
    for(int i = 3; n > 1 &&i < s; i+=2){
        while(n%i==0){
            n/=i;
            res++;
        }
    }
    return res;
}

int calcSteps(vector<int> ar){
    int steps = 0;
    for(int i: ar){
        steps+=numFact(i);
    }
    return steps;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> ar;
        ar.resize(n);
        for(int i = 0; i < n; i++) cin >> ar[i];
        int steps = calcSteps(ar);
        if(steps%2) cout << "Appu\n";
        else cout << "Friend\n";
    }
}
