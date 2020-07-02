#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    long long m;
    int t, n;
    cin >> t;
    bool found[10], allFound;
    for(int i = 1; i <= t; i++){
        allFound = true;
        for(int j = 0; j < 10; j++) found[i] = false;
        cin >> n;
        printf("Case #%d: ", i);
        if(n == 0){
            printf("INSOMNIA\n");
        }
        else{
            for(int j = 1; ; j++){
                m = n*j;
                while(m > 0){
                    found[m%10] = true;
                    m/=10;
                }
                allFound = true;
                for(int k = 0; k < 10; k++){
                    if(found[k]==false){
                        allFound = false;
                        break;
                    }
                }
                if(allFound){
                    printf("%lld\n", n*j);
                    break;
                }
            }
        }
    }
}

