#include<iostream>

using namespace std;

void init(int msq[100][], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            msq[i][j] = -1;
        }
    }
}

bool fillSquare(int msq[100][], int n){
    init(msq, n);
    if(n%2==0) return false;
    int x = 0, y = n/2;
    for(int i = 0; i < )
}

int main(){
    int n, msq[100][100];
    cout << "Enter size : ";
    cin >> n;
    if(!fillSquare(msq, n)){
        cout << "Size must be odd";
        return 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << msq[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
