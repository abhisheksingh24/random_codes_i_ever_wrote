#include<iostream>
#include<cstdlib>
#include<math.h>

using namespace std;

int main(){
    int radius, throws, ins;
    cout << "Enter Radius : ";
    cin >> radius;
    cout << "Enter number of darts to throw : ";
    cin >> throws;
    for(int i = 0; i < throws; i++){
        int x = rand() % radius;
        int y = rand() % radius;
        if((int)(sqrt(x*x + y*y)) < radius) ins++;
    }
    double pi = (4.0*ins)/throws;
    cout << "value of pi = " << pi << endl;
}
