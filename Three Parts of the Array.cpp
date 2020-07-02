#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> vec;
    int n;
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int lastX = -1, lastY = n;
    int i = 0, j = n-1;
    long long sumA = vec[0], sumB = vec[n-1];
    while(i < j){
        if(sumA == sumB){
            lastX = i;
            lastY = j;
            i++;
            sumA+=vec[i];
            j--;
            sumB+=vec[j];
        }
        else if(sumA < sumB){
            i++;
            sumA+=vec[i];
        }
        else{
            j--;
            sumB+=vec[j];
        }
    }
    long long res = 0;
    for(int k = 0; k <= lastX; k++) res+=vec[k];
    cout << res << endl;
}
