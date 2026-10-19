/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e5+10,L=1e6+10;
int mod1=1e9+7,mod2=1e9+9,base1=1331,base2=13331;
int n;
int p1[L],p2[L],hs1[L],hs2[L];
signed main() {
    Cios;
    cin>>n;
    p1[0]=p2[0]=1;
    for (int i=1;i<L;i++) p1[i]=(p1[i-1]*base1)%mod1,p2[i]=(p2[i-1]*base2)%mod2;
    int res=0;
    string ress="";
    for (int i=1;i<=n;i++) {
        string s;
        cin>>s;
        int l=s.size();
        int h1=0,h2=0,len=0;
        for (int j=0;j<l&&j<res;j++) {
            h1=(h1*base1%mod1+s[j])%mod1;
            h2=(h2*base2%mod2+s[j])%mod2;
            if (hs1[res]==(h1+hs1[res-j-1]*p1[j+1]%mod1)%mod1&&hs2[res]==(h2+hs2[res-j-1]*p2[j+1]%mod2)%mod2) len=j+1; 
        }
        for (int j=len;j<l;j++) {
            ress.push_back(s[j]);
            res++;
            hs1[res]=(hs1[res-1]*base1+s[j])%mod1;
            hs2[res]=(hs2[res-1]*base2+s[j])%mod2;
        }
    }
    cout<<ress<<"\n";
    return 0;
}