#include <bits/stdc++.h>
#include<stdio.h>
#include <iostream>
#include <climits>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

ll n;

ll a[5010];

priority_queue <pll, vector<pll>, greater <pll> > pq;

long long dis[50010];

void dijk(long long src)
{
    long long i, j, ad, u;
    for(i=0; i<= 50010; i++)
    {
        dis[i] = LLONG_MAX;
    }


    pq.push(pll(0, src));
    dis[src]=0;

    while(!pq.empty())
    {
        pll v = pq.top();
        u = v.second;
        pq.pop();

        for(i=1; i < n; i++)
        {
            ad = (u + a[i])%a[0];

            if(dis[u]+a[i]<dis[ad])
            {
                dis[ad]=dis[u]+a[i];
                pq.push(pll(dis[ad], ad));
            }
        }
    }
}

int main ()
{
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;

    sl(n);

    for (i = 0; i < n; i++)
    {
        sl(a[i]);
    }

    dijk(0);

    sl(n);

    while(n--)
    {
        sl(x);

        if (dis[x%a[0]] <= x)
            printf("TAK\n");
        else printf("NIE\n");
    }

    return 0;
}
