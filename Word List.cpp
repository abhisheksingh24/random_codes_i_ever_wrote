#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

struct comp{
    bool operator()(string a, string b){
        return(a.compare(b)<0);
    }
};

void putWords(string s, set<string, comp> *words){
    int beg = 0, l = s.size();
    while(!isalpha(s[beg])) beg++;
    for(int i = beg; i<l; i++){
        s[i] = tolower(s[i]);
        if(!isalpha(s[i])){
            (*words).insert(s.substr(beg, i-beg));
            while(i<l && !isalpha(s[i])){
                i++;
            }
            beg = i--;
        }
    }
    if(beg<l) (*words).insert(s.substr(beg, l-beg));
}

int main(){
    string s;
    set<string, comp> words;
    int n, w = 0;
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        putWords(s, &words);
    }
    cout << words.size() << endl;
    for(set<string,comp>::iterator it = words.begin(); it!=words.end(); it++){
        cout << *it <<endl;
    }
}
