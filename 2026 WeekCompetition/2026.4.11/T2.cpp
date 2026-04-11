/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(p) p.begin(),p.end()
intc N=1e5+10,inf=(1<<30);
int n;
string s[N];
int val0[N],val1[N];
int sum0=0,sum1=0,sumv=0,sumkp=0;
bool type0,type1;
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
        val0[i]=count(all(s[i]),'0');
        val1[i]=s[i].size()-val0[i];
        sum0+=val0[i];
        sum1+=val1[i];
        sumv+=val1[i]+val0[i];
    }
    if (sumv==sum0||sumv==sum1) {
        cout<<"0\n";
        return 0;
    }
    for (int i=1;i<=n;i++) {
        if (val0[i]<val1[i]) {
            sumkp+=val1[i];
            type1=1;
        }
        else if (val0[i]>val1[i]) {
            sumkp+=val0[i];
            type0=1;
        }
        else {
            sumkp+=val0[i];
            type0=type1=1;
        }
    }
    if (type0&&type1) cout<<sumv-sumkp<<"\n";
    else if (type0) {
        int minkp=inf;
        for (int i=1;i<=n;i++) minkp=min(minkp,val0[i]-val1[i]);
        cout<<sumv-sumkp+minkp<<"\n";
    }
    else {
        int minkp=inf;
        for (int i=1;i<=n;i++) minkp=min(minkp,val1[i]-val0[i]);
        cout<<sumv-sumkp+minkp<<"\n";
    }
    return 0;
}