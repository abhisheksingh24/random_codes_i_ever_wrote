#include<bits/stdc++.h>

using namespace std;

//we define two helper functions

//returns  true if it is possible to make first kind of bouqet from index i
bool canMakeRose(int beg, string s){
    int n = s.size();
    //if not enough flowers we can't make the bouqet
    if(beg + 2 >= n) return false;
    //otherwise we check if we have desired flowers
    return (s[beg] == '0' && s[beg + 1] == '0' && s[beg + 2] == '0');
}


//returns  true if it is possible to make second kind of bouqet from index i
bool canMakeCosmos(int beg, string s){
    int n = s.size();
    //if not enough flowers we can't make the bouqet
    if(beg + 1 >= n) return false;
    //otherwise we check if we have desired flowers
    // rose then cosmos
    if(s[beg] == '0' && s[beg + 1] == '1') return true;
    //or first cosmos then rose
    if(s[beg] == '1' && s[beg + 1] == '0') return true;
    return false;
}

//function returns max profit..
//the max value of profit for each bouqet may be 1000
//but we don't know the max number of bouqets we can make
//this depends on the length of the string
//I'm choosing int as return type which can hold upto approx 10^9
//so our program works for string lengths less than 10^6
int flowerBouquets(string s, int p, int q){
    //lets choose dp as our dynamic programming array
    //dp[i] denotes maximum profit we can obtain with the string from index i to the end
    //in this denotion dp[0] will store our desired result
    int dp[100000];
    int n = s.size();

    for(int i = n - 1; i >= 0; i--){
        dp[i] = 0;
        //every string can at least generate a profit of zero
        if(canMakeRose(i, s)){
            //if we can make the first type of bouqet
            //next three flowers will be used to make the bouqet
            int profit = p;
            if(i + 3 < n){
                //if further flowers remain after making this bouqet
                //add the maximum profit from the remaining array
                profit = profit + dp[i + 3];
            }
            //choose whichever produces more profit  
            dp[i] = max(dp[i], profit);
        }
        if(canMakeCosmos(i, s)){
            //if we can make the second type of bouqet
            //next two flowers will be user to make this bouqet
            int profit = q;
            if(i + 2 < n){
                //if flowers still remain
                profit = profit + dp[i + 2];
            }
            //choose if this produces more prifit
            dp[i] = max(dp[i], profit);
        }

        //another way could be to ignore this flower and move to next
        if(i + 1 < n) dp[i] = max(dp[i], dp[i + 1]);
    }


    //dp[0] contains the obtainable profit from the entire string
    return dp[0];
}

int main(){
    string s;
    int p, q;
    //take the array as input into a string
    cin >> s;
    //take costs as input
    cin >> p >> q;
    cout << "Max Profit : " << flowerBouquets(s, p, q) << endl;
}