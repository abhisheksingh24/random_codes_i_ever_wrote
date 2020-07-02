#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<long long> coef;
    while(n--+1){
        long long temp;
        cin >> temp;
        coef.push(temp);
    }
    while(!coef.empty() && coef.top()==0) coef.pop();
    if(coef.empty()) cout << "0 0\n";
    else if(coef.size()==1){
        if(coef.top()>0) cout << "1 1\n";
        else cout << "-1 -1\n";
    }
    else if(coef.top()>0){
        if(coef.size()%2 == 0) cout << "1 -1\n";
        else cout << "1 1\n";
    }
    else{
        if(coef.size()%2 == 0) cout << "-1 1\n";
        else cout << "-1 -1\n";
    }
}
