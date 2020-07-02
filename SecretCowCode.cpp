#include<iostream>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

long long rotated(long long n, long long length){
    if(n == length/2) return n-1;
    return n - length/2 - 1;
}

char getChar(string s, long long l, long long n, long long curLength){
    if(curLength == l) return s[n];
    if(n < curLength/2) return getChar(s, l, n, curLength/2);
    return getChar(s, l, rotated(n, curLength), curLength/2);
}

int main(){
    long long n, l, limit;
    string s;
    ifstream fin;
    ofstream fout;
    fin.open("cowcode.in");
    fout.open("cowcode.out");
    fin >> s >> n;
    l = s.length();
    for(limit = l; limit < n; limit*=2);
    fout << getChar(s, l, n-1, limit) << endl;
}
