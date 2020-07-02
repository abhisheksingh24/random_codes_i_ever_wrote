#include<iostream>

using namespace std;

int main(){
    int a, b;
    long long count = 0;
    cin >> a >> b;
    for(int x = 1; x <= a; x++){
        for(int y = 2*x+1, d = 2*x+3; y <= b; y+=d, d+=2){
            count++;
        }
    }
    cout << count << endl;
}
