#include<iostream>
#include<fstream>
#include<vector>
#include<utility>

using namespace std;

vector<int> a;
vector<pair<int, int> > swaps;

void swap(int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main(){
    ifstream inp("sorting.in");
    ofstream otp("sorting.out");
    int n;
    inp >> n;
    a.resize(n);
    for(int &i: a) inp >> i;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] == i+1){
                swap(i, j);
                swaps.push_back(make_pair(i+1, j+1));
                break;
            }
        }
    }
    otp << swaps.size() << endl;
    for(auto p: swaps) otp << p.first << " " << p.second << endl; 
}
