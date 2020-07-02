#include<iostream>
using namespace std;
string comp(string s)
{
    char beg = s[0];
    int cnt=0;
    while(beg==s[cnt])
    {
        cnt++;
    }
        if(cnt==1)
        {
            char a = beg;
        }
}

int main()
{
if(comp("aaabhsdfff")==true) cout << "Yes\n";
else cout << "No\n";
}
