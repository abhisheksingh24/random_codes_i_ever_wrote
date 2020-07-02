#include<iostream>
#include<string>

using namespace std;

int A[26], B[26];

void init(){
    for(int i = 0; i < 26; i++) A[i] = B[i] = 0;
}

bool uniquePair(){
    for(int i = 0; i < 26; i++){
        if(A[i]>=2 && B[i]==0) return true;
    }
    return false;
}

bool noUnique(int mover[], int waiter[]){
    for(int i = 0 ; i < 26; i++){
        if(mover[i]>0 && waiter[i]==0) return false;
    }
    return true;
}

char play(string s, string t){
    init();
    for(char c : s) A[c-'a']++;
    for(char c : t) B[c-'a']++;
    if(uniquePair()) return 'A';
    else if(noUnique(A, B)) return 'B';
    else if(noUnique(B, A)) return 'A';
    else return 'B';
}

int main(){
    int T;
    string s, t;
    cin >> T;
    while(T--){
        cin >> s >> t;
        cout << play(s,t) << endl;
    }
}
