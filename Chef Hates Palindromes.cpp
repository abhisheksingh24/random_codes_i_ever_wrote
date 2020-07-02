#include<iostream>
#include<string>

using namespace std;

string construct(int a){
    char c = 'a';
    string s = "";
    while(a--){
        s.push_back(c);
        c++;
    }
    return s;
}

string makestr(int n, int a){
    string part = construct(a);
    string res = "";
    for(int i = 0; i < n/a; i++) res.append(part);
    return res+part.substr(0,n%a);
}

int main(){
    int t, n, a;
    cin >> t;
    while (t--){
        cin >> n >> a;
        if(a==1) cout << n << " ";
        else if(a==2){
            if(n<=2) cout << "1 ";
            else if(n==3) cout << "2 ";
            else cout << "3 ";
        }
        else cout << "1 ";
        if(n==3 && a==2) cout << "abb\n";
        else cout << makestr(n, a) << endl;
    }
}
