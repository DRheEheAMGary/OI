/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
signed main() {
    Cios;
    // freopen("pfs.in","r",stdin);
    // freopen("pfs.out","w",stdout);
    for (int n=1;n<=9;n++) {
        for (int k=1;k<=n;k++) {
            vector <int> a;
            for (int i=1;i<=n;i++) a.push_back(i);
            intl res=0;
            do {
                vector <int> _a(a);
                sort(_a.begin(),_a.begin()+k);
                vector <intl> dp(n+1,0);
                for (int i=1;i<=n;i++) {
                    dp[i]=1;
                    for (int j=1;j<i;j++) {
                        if (_a[j-1]<_a[i-1]) dp[i]=max(dp[j]+1,dp[i]);
                    }
                }
                intl maxdp=-1;
                for (int i=1;i<=n;i++) maxdp=max(maxdp,dp[i]);
                if (maxdp>=n-1) res++;
            } while (next_permutation(a.begin(),a.end()));
            // cout<<res<<" ";
            int fff=1;
            for (int i=1;i<=k;i++) fff*=i;
            cout<<"\t"<<res/fff;
        }
        cout<<"\n";
    }
    return 0;
}

/*
g++ -g pfs.cpp -o pfs.exe -std=c++14 -O2 -static; echo "finish"; .\pfs.exe
*/