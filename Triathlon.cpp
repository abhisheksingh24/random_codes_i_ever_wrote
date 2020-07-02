#include<iostream>
#include<algorithm>

using namespace std;

void disp(int a[], int n){
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout <<endl;
}

struct times{
    int cobol, others;
};

bool comp(times a, times b){
    return(a.others>b.others);
}

int main(){
    int n, temp, totTime[20000], curTime = 0;
    times t[200000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t[i].cobol >> t[i].others >> temp;
        t[i].others+=temp;
    }
    sort(t, t+n, comp);
    for(int i = 0; i < n; i++){
        curTime+=t[i].cobol;
        totTime[i] = curTime + t[i].others;
    }
    cout << *max_element(totTime, totTime+n) << endl;
}
