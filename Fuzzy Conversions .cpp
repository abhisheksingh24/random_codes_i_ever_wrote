#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, c, x, y, z;
        cin >> a >> b >> c >> x >> y >> z;
        x = x - a;
        y = y - b;
        z = z - c;
        if(x < 0) x = -1 * (abs(x) % 2);
        else x = abs(x) % 2;
        if(y < 0) y = -1 * (abs(y) % 2);
        else y = abs(y) % 2;
        if(z < 0) z = -1 * (abs(z) % 2);
        else z = abs(z) % 2;
        if(x > y) swap(x, y);
        if(x > z) swap(x, z);
        if(y > z) swap(y, z);
        if(x == -1){
            if(y == -1){
                if(z == -1){
                    cout << 
                }
                else if(z == 0){

                }
                else{

                }
            }
            else if(y == 0){
                if(z == 0){

                }
                else{

                }
            }
            else{

            }
        }
        else if(x == 0){
            if(y == 0){
                if(z == 0){

                }
                else{

                }
            }
            else{

            }
        }
        else{

        }
    }
}