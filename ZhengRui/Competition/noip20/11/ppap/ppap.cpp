/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e3+10;
constexpr intl mod=998244353;
string s;
int lcp[N][N],dp1[N][N],dp2[N][N],diff1[N][N],diff2[N][N],cnt[N][N],res[N][N];
signed main() {
    Cios;
    // freopen("ppap.in","r",stdin);
    // freopen("ppap.out","w",stdout);
    int T;cin>>T;
    while (T--) {
        cin>>s;
        int n=s.size();
        for (int i=1;i<=n+2;i++) for (int j=1;j<=n+2;j++) lcp[i][j]=dp1[i][j]=dp2[i][j]=diff1[i][j]=diff2[i][j]=cnt[i][j]=res[i][j]=0;
        s=" "+s;
        for (int i=n;i>=1;i--) {
            for (int j=n;j>=1;j--) lcp[i][j]=(s[i]==s[j]?(lcp[i+1][j+1]+1):0);
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                int len=min(lcp[i][j],j-i);
                if (len<=0) continue;
                ++diff1[i][j]%=mod;
                (--diff1[i][j+len]+=mod)%=mod;
                ++diff2[i][j]%=mod;
                (--diff2[i+len][j]+=mod)%=mod;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) dp1[i][j]=(dp1[i][j-1]+diff1[i][j])%mod;
        }
        for (int j=1;j<=n;j++) {
            for (int i=1;i<=n;i++) dp2[j][i]=(dp2[j-1][i]+diff2[j][i])%mod;
        }
        for (int i=1;i<=n;i++) {
            intl suff=0;
            for (int j=i;j>=1;j--) {
                (suff+=dp1[j][i])%=mod;
                if (j-1>=1) cnt[j-1][i]=suff;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) res[i][j]=(((intl)res[i-1][j]+res[i][j-1]-res[i-1][j-1]+cnt[i][j])%mod+mod)%mod;
        }
        intl tres=0;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                if (!dp2[i][j]) continue;
                intl temp=(((intl)res[j-1][j-1]-res[j-1][i]-res[i][j-1]+res[i][i])%mod+mod)%mod;
                if (temp<0) temp=0;
                tres=(tres+dp2[i][j]*temp)%mod;
            }
        }
        cout<<tres<<"\n";
    }
    return 0;
}

/*
g++ -g ppap.cpp -o ppap.exe -std=c++14 -O2 -static; echo "finish"; .\ppap.exe; rm ppap.exe
cd $work && g++ ppap.cpp -o ppap -std=c++14 -O2 && echo "finish" && ./ppap && rm ppap
*/