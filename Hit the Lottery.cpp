#include<iostream>

using namespace std;

int main(){
    int div[5] = {100, 20, 10, 5, 1};
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < 5 && n > 0; i++){
        cnt += n/div[i];
        n = n % div[i];
    }
    cout << cnt << endl;
}
