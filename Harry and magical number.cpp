#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> numbers;

long long sum(int ind){
    long long s = 0;
    for(int i = 0; i < ind; i++) s+=numbers[i];
    return(s+(n-ind)*numbers[ind]);
}

long long searchNum(int l, int r, long long s){
    //cout << "l = "<<l<<"  r = "<<r<<"  s = "<<s<<endl;
    if(l>r) return -1;
    int mid = l + (r-l)/2, curSum = sum(mid);
    //cout<<"curSum = "<<curSum<<endl;
    if(curSum==s) return numbers[mid];
    if(curSum>s) return searchNum(l,mid-1,s);
    return searchNum(mid+1,r,s);
}


int main(){
    int t, temp;
    long long s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        numbers.clear();
        for(int i = 0; i < n; i++){
            cin >> temp;
            numbers.push_back(temp);
        }
        sort(numbers.begin(), numbers.end());
        cout << searchNum(0, n-1,s) << endl;
    }
}
