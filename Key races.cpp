#include<iostream>

using namespace std;

int main(){
    int s, v1, v2, t1, t2, time1, time2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    time1 = s*v1 + 2*t1;
    time2 = s*v2 + 2*t2;
    if(time1 < time2) cout << "First\n";
    else if(time2 < time1) cout << "Second\n";
    else cout << "Friendship\n";
}
