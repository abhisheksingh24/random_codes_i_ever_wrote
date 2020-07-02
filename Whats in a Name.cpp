#include<bits/stdc++.h>

using namespace std;

void print(vector<string> parts, int n){
    for(int i = 0; i < n-1; i++){
        cout << char(toupper(parts[i][0])) << ". ";
    }
    cout<<char(toupper(parts[n-1][0]));
    for(int i = 1; i < parts[n-1].size(); i++){
        cout << char(tolower(parts[n-1][i]));
    }
    cout << endl;
}

int main(){
    vector<string> parts;
    int t;
    string s, temp;
    cin >> t;
    cin.ignore();
    while(t--){
        parts.clear();
        getline(cin, s);
        istringstream iss(s);
        while(iss >> temp){
            parts.push_back(temp);
        }
        int l = parts.size();
        print(parts, l);
    }
}
