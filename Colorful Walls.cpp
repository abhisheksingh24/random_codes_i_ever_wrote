#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > ar;

int main(){
    int n;
    cin >> n;
    ar.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            ar[i].push_back(temp);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ar[n-j-1][i] << " ";
        }
        cout << endl;
    }
}
