#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(){
    int n;
    set<char> characters;
    string a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    int pre = 0;
    for(int i = 0; i < n/2; i++){
        characters.clear();
        characters.insert(a[i]);
        characters.insert(b[i]);
        characters.insert(a[n-1-i]);
        characters.insert(b[n-1-i]);
        if(characters.size() == 4) pre+=2;
        else if(characters.size() == 3) pre+=1;
    }
    if(n%2 && a[n/2]!=b[n/2]) pre++;
    cout << pre << endl;
}
