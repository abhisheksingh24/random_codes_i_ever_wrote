#include<iostream>
#include<math.h>

using namespace std;

bool perfectSquare(long long n){
    int root = sqrt(n);
    return (root*root == n);
}

bool possible(long long a, long long b){
    long long sq1, sq2, l = sqrt(a);
    for(long long i = 1; i <= l; i++){
        if(a%i==0){
            sq1 = i*i;
            sq2 = (a/i)*(a/i);
            if(perfectSquare(i) && (int)(sqrt(i))*sq2 == b) return true;
            if(perfectSquare(a/i) && (int)(sqrt(a/i))*sq1 == b) return true;
        }
    }
    return false;
}

int main(){
    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(possible(a,b)) cout << "Yes\n";
        else cout << "No\n";
    }
}
