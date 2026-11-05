/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include "period.h"
int qpow (int a,int b) {
    int res=1;
    while (b>0) {
        if (b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
vector <pair<int,int>> prim;
int solve(int n, int q) { 
    int temp=n;
    for (int i=2;i*i<=temp;i++) {
        if (temp%i==0) {
            int cnt=0;
            while (temp%i==0) temp/=i,cnt++;
            prim.push_back({i,cnt});
        }
    }
    if (temp>1) prim.push_back({temp,1});
    int res=1;
    for (auto [pr,cnt]:prim) {
        int l=1,r=cnt,resp=0;
        while (l<=r) {
            int mid=(l+r)>>1;
            int len=n/qpow(pr,mid);
            if (query(len)==n-len) l=mid+1,resp=mid;
            else r=mid-1;
        }
        res*=qpow(pr,resp);
    }
    return res;
}
/*
g++ -g period.cpp -o period.exe -std=c++14 -O2 -static; echo "finish"; .\period.exe; rm period.exe
cd $work/ZhengRui/Competition/noip20/9/period && g++ period.cpp implementer.cpp -o period -std=c++14 -O2 && echo "finish" && ./period && rm period
*/
