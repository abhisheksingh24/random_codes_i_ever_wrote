#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main(){
    int t;
    long long y;
    cin >> t;
    while(t--){
        cin >> y;
        long long cnt = 0;
        for(long long i = max(0ll, y-700); i < y; i++){
            cnt+=(sqrt(i));
        }
        cout << cnt << endl;
    }
}
