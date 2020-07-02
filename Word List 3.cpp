#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<set>

using namespace std;

void convert(string *s){
    int l = (*s).size();
    for(int i = 0; i < l; i++){
        if(!isalpha((*s)[i])) (*s)[i]=' ';
        else (*s)[i] = tolower((*s)[i]);
    }
}

int main(){
    string s,temp;
    set<string> words;
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        convert(&s);
        istringstream iss(s);
        iss >> temp;
        while(!iss.eof()){
            words.insert(temp);
            iss >> temp;
        }
    }
    cout << words.size() << endl;
    for(set<string>::iterator it = words.begin(); it!=words.end(); it++){
        cout << *it <<endl;
    }
}
