#include<iostream>
#include<string>

using namespace std;

string multiply(string s, int n){
    if(n<=1) return s;
    string res = multiply(s+s, n/2);
    if(n%2 != 0) res+=s;
    return res;
}

int main(){
    string a;
    cout << a.max_size() << endl;
    int t, na, nb, minGroupA, maxGroupA, minGroupB, maxGroupB, x, y;
    string s;
    cin >> t;
    while(t--){
        s.clear();
        na = nb = 0;
        cin >> s;
        cin >> x >> y;
        for(char c : s){
            if(c == 'a') na++;
            else nb++;
        }
        minGroupA = (na+x-1)/x;
        maxGroupA = na;
        minGroupB = (nb+y-1)/y;
        maxGroupB = nb;
        cout << "a from " << minGroupA << " to " << maxGroupA <<"\tb from " << minGroupB << " to " << maxGroupB << endl;
        if(minGroupA > maxGroupB){

        }
        else if(minGroupB > maxGroupB){

        }
        else{
            int rangeMin = max(minGroupA, minGroupB), rangeMax = min(maxGroupA, maxGroupB);
            int groups = rangeMin + (rangeMax - rangeMin)/2;
            int inOneGroupA = (na + groups - 1)/groups, inOneGroupB = (nb + groups - 1)/groups;
            string subString = string(inOneGroupA, 'a') + string(inOneGroupB, 'b');
            cout << "na = " << na << "\tnb = " << nb << endl;
            cout << "range : " << rangeMin << " to " << rangeMax << endl;
            cout << inOneGroupA << "in a and " << inOneGroupB << " in b\n";
            cout << "One group : " << subString << endl;
            cout << na-inOneGroupA*(groups-1) << " a left\n";
            cout << nb-inOneGroupB*(groups-1) << " b left\n";
            string fullString = multiply(subString, groups-1) + string(na-inOneGroupA*(groups-1), 'a') + string(nb-inOneGroupB*(groups-1), 'b');
            cout << fullString << endl;
        }
    }
}
