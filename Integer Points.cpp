#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, pq, o1 = 0, o2 = 0, e1 = 0, e2 = 0;
        cin >> n;
        while(n--){
            cin >> pq;
            if(pq % 2) o1++;
            else e1++;
        }
        cin >> n;
        while(n--){
            cin >> pq;
            if(pq % 2) o2++;
            else e2++;
        }
        cout << 1LL * o1 * o2 + 1LL * e1 * e2 << endl;
    }
}