#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

long long power(long long int b, long long int e){
    if(e==0) return 1;
    if(e%2==0) return power(b*b, e/2);
    return b*power(b*b, e/2);
}

int main(){
    int t, n, m, cnt;
    vector<int> ar;
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n >> m;
        ar.resize(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
            if(ar[i]%m == 0) cnt++;
        }
        cout << power(2, cnt) - 1 << endl;
    }
}
