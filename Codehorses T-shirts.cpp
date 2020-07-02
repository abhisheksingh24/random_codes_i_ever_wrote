#include<iostream>
#include<vector>
#include<string>

using namespace std;

int findInd(string str){
    if(str.back()=='S'){
        return str.length() - 1;
    }
    if(str.back()=='M'){
        return 4;
    }
    return str.length() + 4;
}

int main(){
    int n;
    vector<int> ar1, ar2;
    cin >> n;
    ar1.resize(9);
    ar2.resize(9);
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        ar1[findInd(str)]++;
    }
    for(int i = 0; i < n; i++){
        cin >> str;
        ar2[findInd(str)]++;
    }
    /*
    for(int i = 0; i < 9; i++){
        cout << ar1[i] << " ";
    } cout << endl;
    for(int i = 0; i < 9; i++){
        cout << ar2[i] << " ";
    } cout << endl;
    */
    int steps = 0;
    for(int i = 0; i < 9; i++){
        if(ar1[i] > ar2[i]) steps+=(ar1[i] - ar2[i]);
    }
    cout << steps << endl;
}
