#include<iostream>

using namespace std;

char str[100000];

void reset(){
    for(int i = 0; i < 100000; i++) str[i] = '\0';
}

void correct(int x, int y){

}

int main(){
    int t, x, y;
    while(t--){
        reset();
        cin >> str;
        cin >> x >> y;
        correct(x, y);
        cout << str << endl;
    }
}
