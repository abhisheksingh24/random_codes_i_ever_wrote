#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for(int& i: A) cin >> i;
    B[0] = 0;
    for(int i = 1; i < n; i++) B[i] = A[i] - B[i - 1];
    int inc = abs(A[0] - B[n - 1]);
    for(int i = 0; i < n; i++){
        if(i % 2) B[i] -= inc / 2;
        else B[i] += inc / 2;
    }
    for(int& i: B) i *= 2;
    int temp = B[n - 1];
    for(int i = n - 1; i > 0; i--) B[i] = B[i - 1];
    B[0] = temp;
    for(int& i: B) cout << i << " ";
    cout << endl;
}