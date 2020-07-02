#include<iostream>
#include<set>

using namespace std;

#define ms multiset <int>
#define msi multiset <int, greater<int> >

void disp(ms a){
    for(ms::iterator it = a.begin(); it!=a.end(); it++){
        cout <<*it << " ";
    }
    cout << endl;
}

int skew(ms a, ms b, int k){
    int t1, t2;
    ms::iterator it1, it2;
    while(k--){
        it1 = a.end(); it1--;
        t1 = *it1; t2 = *b.begin();
        if(t2 >= t1) break;
        a.erase(it1); b.erase(b.begin());
        a.insert(t2); b.insert(t1);
    }
    it1 = a.end(); it1--; it2 = b.end(); it2--;
    return(*it1 + *it2);
}

int main(){
    ms a, b;
    int n, k, temp;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> temp;
        a.insert(temp);
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
        b.insert(temp);
    }
    cout << min(skew(a,b,k), skew(b,a,k))<<endl;
    return 0;
}
