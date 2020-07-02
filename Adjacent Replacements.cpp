#include<iostream>
#include<vector>

using namespace std;

 int main(){
    int n;
    vector<int> vec;
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    for(int i = 0; i < n; i++){
        if(vec[i] % 2 == 0) vec[i]--;
    }
    for(int i = 0; i < n; i++) cout << vec[i] << " ";
    cout << endl;
 }
