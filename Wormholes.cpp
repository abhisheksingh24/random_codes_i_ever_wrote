#include<iostream>
#include<algorithm>

using namespace std;

int n, x, y, v[100000], w[100000];


struct contest{
    int beg, end;
}c[100000];

bool comp(contest s1, contest s2){
    return(s1.beg < s2.beg);
}

bool cIn(int r, int cl, int cr){
    for(int i = cl; i <= cr; i++){
        if(c[i].end <= r) return true;
    }
    return false;
}

int main(){

    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) cin >> c[i].beg >> c[i].end;
    for(int i = 0; i < x; i++) cin >> v[i];
    for(int i = 0; i < y; i++) cin >> w[i];
    sort(v, v+x);
    sort(w, w+y);
    sort(c, c+n, comp);
    int xi = 0, yil=0, yir=y-1, cil=0, cir = n-1, min = 1000001;
    while(xi < x){
        while(cil < n && c[cil].beg < v[xi]) cil++;
        while(yil>=0 && w[yil] < v[xi]) yil++;
        while(yir<y && w[yir]-v[xi] >= min) yir--;
        while(cir>=0 && c[cir].beg > w[yir]) cir--;
        if(cil>=n || yil<0 || yir>=y || cir<0 || cil>cir || yil>yir) break;
        bool minned = false;
        for(int i = yil; i <= yir; i++){
            if(cIn(w[i], cil, cir)){
                min = w[i] - v[xi];
                minned = true;
            }
        }
        if(!minned) break;
        xi++;
    }
    cout << min+1 << endl;
}
