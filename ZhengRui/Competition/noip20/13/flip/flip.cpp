/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,a[N],b[N];
vector <int> vl1,vl2;
signed main() {
    Cios;
    freopen("flip.in","r",stdin);
    freopen("flip.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        vl1.clear();vl2.clear();
        intl res=0;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            res+=a[i];
        }
        for (int i=1;i<=n;i++) {
            cin>>b[i];
            if (i%2==0) vl2.push_back(b[i]-a[i]);
            else vl1.push_back(b[i]-a[i]);
        }
        auto cmp=[] (const int &a,const int &b) {return a>b;};
        sort(vl1.begin(),vl1.end(),cmp);
        sort(vl2.begin(),vl2.end(),cmp);
        int l=min(vl1.size(),vl2.size());
        for (int i=0;i<l;i++) {
            if (vl1[i]+vl2[i]>0) res+=vl1[i]+vl2[i];
            else break;
        }
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ -g flip.cpp -o flip.exe -std=c++14 -O2 -static; echo "finish"; .\flip.exe; rm flip.exe
cd $work/ZhengRui/Competition/noip20/13/flip && g++ flip.cpp -o flip -std=c++14 -O2 && echo "finish" && ./flip && rm flip
*/