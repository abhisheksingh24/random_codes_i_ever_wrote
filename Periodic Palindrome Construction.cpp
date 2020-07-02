#include<iostream>
#include<string>

using namespace std;

string construct(int len){
    return string(1,'b')+string(len-2, 'a')+string(1,'b');
}

void repeat(string s, int rep){
    for(int i = 0; i < rep; i++) cout << s;
}

int main(){
    int t, n , p;
    cin >> t;
    while(t--){
        cin >> n >> p;
        if(p<3) cout << "impossible\n";
        else{
            string part = construct(p);
            repeat(part, n/p);
            cout << endl;
        }
    }
}
