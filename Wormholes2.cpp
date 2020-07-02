#include<iostream>
#include<algorithm>

using namespace std;

int n, x, y, v[100000], w[100000];


struct contest{
    int beg, end;
}c[100000];

bool comp(contest s1, contest s2){
    return(s1.end - s1.beg < s2.end - s2.beg);
}

bool cIn(int r, int cl, int cr){
    for(int i = cl; i <= cr; i++){
        if(c[i].end <= r) return true;
    }
    return false;
}

int left(int a){
    if(v[0] > a) return(-1);
    int m, l = 0, r = x-1;
    while(l<r){
        m = l + (r-l)/2 + 1;
        if(v[m]<=a) l = m;
        else r = m-1;
    }
    return(v[l]);
}

int right(int a){
    if(w[y-1] < a) return(-1);
    int m, l = 0, r = y-1;
    while(l<r){
        m = l + (r-l)/2;
        if(w[m] >= a) r = m;
        else l = m+1;
    }
    return(w[r]);
}

int main(){
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) cin >> c[i].beg >> c[i].end;
    for(int i = 0; i < x; i++) cin >> v[i];
    for(int i = 0; i < y; i++) cin >> w[i];
    sort(v, v+x);
    sort(w, w+y);
    sort(c, c+n, comp);
    int min = 1000001, l, r;
    for(int i = 0; i < n; i++){
        if(c[i].end-c[i].beg >= min) break;
        l = left(c[i].beg);
        r = right(c[i].end);
        if(l!=-1 && r!=-1 && r-l < min) min = r-l;
    }
    cout << min+1 << endl;
}

