#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int t;
    fin >> t;
    for(int i = 1; i <= t; i++){
        string s;
        fin >> s;
        int b = 0, dot = 0;
        for(char c: s){
            if(c == 'A') continue;
            if(c == 'B') b++;
            else dot++;
        }
        if(dot && b >= dot) fout << "Case #" << i << ": Y" << endl;
        else fout << "Case #" << i << ": N" << endl;
    }
}