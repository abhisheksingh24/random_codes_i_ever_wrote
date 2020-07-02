#include<iostream>
#include<vector>

using namespace std;

#define intMin -2147483648

int n, k;
vector<int> points;

int sum(int beg, int end){
    if(beg>end) return intMin;
    if(beg==end) return points[beg];
    if(beg+1==end) return(points[beg]+points[end]);
    return (points[end] + max(sum(beg,end-1), sum(beg,end-2)));
}

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

int maxSum(){
    int curMax = intMin;
    for(int i = k+1; i < n; i++){
        curMax = max(curMax, max(sum(k+1,i),sum(k+2,i))+max(sum(0,i-1),sum(0,i-2)));
        cout << "i = "<<i << " : "<< max(sum(k+1,i),sum(k+2,i))+max(sum(0,i-1),sum(0,i-2)) << endl;
    }
    curMax = max3(curMax, sum(0,k-1),sum(0,k-2));
    if(k==0) curMax = max(curMax, 0);
    return curMax;
}

int main(){
    int temp;
    cin >> n >> k;
    k--;
    for(int i = 0; i < n; i++){
        cin >> temp;
        points.push_back(temp);
    }
    cout << maxSum() << endl;
}

