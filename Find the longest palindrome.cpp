#include<iostream>

using namespace std;

bool isPal[5000][5000];

struct loc{
    int beg, end;
};

loc solve(char ar[], int length){
    int maxSize = 0;
    loc res;
    for(int l = 1; l <= length; l++){
        for(int i=0,j=l-1; j<length; i++,j++){
            if(l==1) isPal[i][j] = true;
            else if(l==2) isPal[i][j] = (ar[i]==ar[j]);
            else{
                if(ar[i]!=ar[j]) isPal[i][j] = false;
                else isPal[i][j] = isPal[i+1][j-1];
            }
            if(isPal[i][j] && j-i>=maxSize){
                maxSize = i-j+1;
                res.beg = i;
                res.end = j;
            }
        }
    }
    return res;
}

void print(char ar[], int beg, int end){
    for(int i = beg; i <= end; i++) cout << ar[i];
    cout << endl;
}

int main(){
    loc pal;
    char str[5000];
    int n;
    cin >> n;
    cin >> str;
    pal = solve(str, n);
    cout << pal.end - pal.beg + 1 << endl;
    print(str, pal.beg, pal.end);
}
