#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> seq;
multiset<int> sorted;

int main(){
    multiset<int> :: iterator it;
    int n, temp, maxSum, toReplace;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        seq.push_back(temp);
        sorted.insert(temp + (i+1));
    }
    for(int i = 0; i < n; i++){
        it = sorted.end();
        maxSum = *(--it) + i;
        toReplace = seq[n-i-1] + (n - i);
        it = sorted.find(toReplace);
        sorted.erase(it);
        toReplace-=n;
        sorted.insert(toReplace);

        cout << maxSum << " ";
    }
    cout << endl;
}
