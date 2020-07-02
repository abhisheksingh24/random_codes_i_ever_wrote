#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> s;

int addDee(int d, string st){
    cout << "dee : " << st << endl;
    for(char c: st){
        if(c=='0') d++;
    }
    return d;
}

int addDum(int d, string st){
    cout << "dum : " << st << endl;
    for(char c: st){
        if(c=='1') d++;
    }
    return d;
}

int main(){
    int t, n, dee, dum;
    string name;
    cin >> t;
    while(t--){
        dee=dum=0;
        cin >> n >> name;
        s.clear();
        s.resize(n);
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++){
            if(s[i][0] == '0') dee = addDee(dee, s[i]);
            else dum = addDum(dum, s[i]);
        }
        cout << dee << ", "  << dum << endl; 
        if(name=="Dee"){
            cout << "Dee doing\n";
            if(dee > dum) cout << "Dee\n";
            else cout << "Dum\n";
        }
        else{
            if(dum > dee) cout << "Dum\n";
            else cout << "Dee\n";
        }
    }
}