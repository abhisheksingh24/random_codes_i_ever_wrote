#include<iostream>
#include<math.h>

using namespace std;

int main(){
    long long b, cnt = 0;
    cin >> b;
    for(int i = 1; i <= sqrt(b); i++){
        if(b%i) continue;
        cnt++;
        if(i != b/i) cnt++;
    }
    cout << cnt << endl;
}