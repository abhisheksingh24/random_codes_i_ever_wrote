#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<vector<bool> > digit;

bool canForm(multiset<int> digits, int n){
    /*
    cout << "digits : ";
    for(auto a : digits) cout << a << " ";
    cout << endl;
    cout << "Current status : \n";
    for(auto a: digit){
        for(auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    */
    if(digits.empty()) return true;
    multiset<int> temp(digits);
    for(int d: digits){
        for(int i = 0; i < n; i++){
            if(digit[i][d]){
                digit[i][d] = false;
                temp.erase(temp.find(d));
                /*
                cout << "digits after deletion: ";
                for(auto a : temp) cout << a << " ";
                cout << endl;
                */
                bool found = false;
                if(canForm(temp, n)) found = true;
                temp.insert(d);
                digit[i][d] = true;
                if(found) return true;
            }
        }
    }
    //cout << "Returning false\n";
    return false;
}

int maxNum(int n){
    int res = 0;
    for(int i = 1; ; i++){
        multiset<int> digits;
        for(int temp = i; temp > 0; temp/=10){
            digits.insert(temp%10);
        }
        if(canForm(digits, n)) res = i;
        else break;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    digit.resize(n);
    for(int i = 0; i < n; i++){
        digit[i].resize(10);
        for(int j = 0; j < 6; j++){
            int d;
            cin >> d;
            digit[i][d] = true;
        }
    }
    /*
    for(auto a: digit){
        for(auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    */
    cout << maxNum(n) << endl;
}

