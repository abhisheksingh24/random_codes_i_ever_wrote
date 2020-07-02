#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int t, n;
    string s;
    vector<int> counts;
    cin >> t;
    while(t--){
        cin >> s >> n;
        int l = s.length();
        counts.resize(l);

        counts[0] = s[0]=='a' ? 1 : -1;
        for(int i = 1; i < l; i++){
            if(s[i] == 'a') counts[i] = counts[i-1] + 1;
            else counts[i] = counts[i-1] - 1;
        }

        //cout << "Counts : ";
        //for(int x : counts) cout << x << " "; cout  << endl;

        int totalCount = counts[l-1];

        long long res = 0;
        if(totalCount == 0){
            for(int x : counts){
                if(x > 0){
                    res += n;
                    //cout << n;
                }
                //else cout << "0 ";
            }
        }

        else if(totalCount > 0){
            for(int x : counts){
                if(x <= 0){
                    //cout << n << " - " << -1*x << "/" << totalCount << " - " << 1 << endl;
                    res += max(0, n - (-1*x)/totalCount - 1);
                    //res += (max((long long)(0), n - abso(x)/totalCount - 1));
                    //cout << max(0, n - abs(x)/totalCount - 1) << " ";
                }
                else{
                    res+= n;
                    //cout << n << " ";
                }

            }
        }

        else{
            for(int x : counts){
                if(x > 0){
                    if(x % (-1*totalCount) == 0) res += min(n, x/(-1*totalCount));
                    else res += min(n, x/(-1*totalCount) + 1);
                    //res += (min(n, (x+totalCount-1)/totalCount));
                    //cout << min(n, (x+totalCount-1)/totalCount) << " ";
                }
                //else cout << "0 ";
            }
        }

        //cout << endl;

        cout << res << endl;
    }
}
