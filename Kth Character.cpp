#include<iostream>

using namespace std;

int main(){
    long long n = 0;
    for(int i = 1; n < (9223372036854775807-1)/2; i++){
        n*=2; n++;
        cout << i <<" : "<<n<<endl;
    }
}
