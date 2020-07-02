#include<iostream>
#include<stdio.h>
#include<string>
#include<limits>

using namespace std;

void pn(char c, int n){
    while(n--) printf("%c", c);
}

void print(char a, char b, int na, int nb, int x, int y){
    int cnta = 0, cntb = 0;
    if(na > (nb+1)*x){
        for(int i = 0; i < nb; i++){
             //   cout << "Looping\n";
            pn(a, x);
            pn(b, 1);
        }
        na-=(nb*x);
        int l = min(na, x);
        pn(a, l);
        na-=l;
        for(int i = 0; i < na/x; i++){
           // cout << "Looping 2\n";
            pn('*', 1);
            pn(a, x);
        }
        if(na%x>0){
            pn('*', 1);
            pn(a, na%x);
        }
    }
    else{
        bool rev;
        //cout << "na = " << na <<"\tx = " << x << "nb= " <<nb << "\ty = " << y << endl;
        int partsA = (na+x-1)/x, partsB = (nb+y-1)/y;
        //cout << "Parts A : " << partsA << "\tParts B : " << partsB << endl;
        if(partsA > partsB) partsB = partsA - 1;
        else if(partsB > partsA){
            partsA = partsB - 1;
            rev = true;
        }
        //cout << "Parts A : " << partsA << "\tParts B : " << partsB << endl;
        //float ma = na/partsA, mb = nb/partsB;
        //cout << a<<" = " << ma << b<<" = " << mb << endl;
        while(na>0 || nb > 0){
         //       cout << "Looping 3\n";
            //cout << "In loop\n";
            int l = partsA>0 ? na/partsA : 0;
            if(!rev){
                for(int i = 0; i < l; i++){
                    printf("%c",a);
                    na--;
                }
                partsA--;
            }
            l = partsB>0 ? nb/partsB : 0;
            for(int i = 0; i < l; i++){
                printf("%c",b);
                nb--;
            }
            partsB--;
            if(rev){
                for(int i = 0; i < l; i++){
                    printf("%c",a);
                    na--;
                }
                partsA--;
            }
        }
    }
}

int main(){
    int t, x, y, na, nb, nmx, nmn, kmx, kmn;
    string s;
    char mx, mn;
    scanf("%d", &t);
    while(t--){
        na =  nb = 0;
        cin >> s;
        //cout << "String read\n";
        scanf("%d %d", &x, &y);
        //cout << "numbers read\n";
        for(char c : s){
          //      cout << "reading characters\n";
            if(c=='a') na++;
            else nb++;
        }
        if(na>nb){
            nmx = na;
            nmn = nb;
            kmx = x;
            kmn = y;
            mx = 'a';
            mn = 'b';
        }
        else{
            nmx = nb;
            nmn = na;
            kmx = y;
            kmn = x;
            mx = 'b';
            mn = 'a';
        }
        //cout << "calling\n";
        print(mx, mn, nmx, nmn, kmx, kmn);
        printf("\n");
    }
}
