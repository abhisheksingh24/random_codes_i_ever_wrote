#include<iostream>

using namespace std;

int time(int c, int u, int v, int a, int l){
    int pagesRead = u;
    for(int daysPassed = 1; ; daysPassed++){
        if(pagesRead >= c) return(daysPassed);
        pagesRead =  max(0,pagesRead-l) + min(u+daysPassed*a, v);
    }
}

int main(){
    int c, u, v, a, l, pagesRead;
    cin >> c >> u >> v >> a >> l;
    cout << time(c,u,v,a,l) << endl;
}
