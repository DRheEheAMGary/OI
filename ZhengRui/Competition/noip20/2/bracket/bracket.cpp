/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
string s;
short val[N];
signed main() {
    Cios;
    // freopen("bracket.in","r",stdin);
    // freopen("bracket.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>s;
        s="0"+s+"0";
        int l=s.length();
        for (int i=1;i<l;i++) val[i]=s[i]-s[i-1];
        int maxd=-1,idxd=-1;
        for (int i=1;i<l-1;i++) {
            if (abs(val[i])+abs(val[i+1])-abs(s[i+1]-s[i-1])>maxd) {
                maxd=abs(val[i])+abs(val[i+1])-abs(s[i+1]-s[i-1]);
                idxd=i;
            }
        }
        if (maxd>0) {
            s[idxd]=s[idxd-1];
            val[idxd]=0;
            val[idxd+1]=s[idxd+1]-s[idxd];
        }
        for (int i=1;i<l;i++) {
            for (int j=1;j<=val[i];j++) cout<<"(";
            for (int j=-1;j>=val[i];j--) cout<<")";
            if (i!=l-1) cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}

/*
g++ bracket.cpp -o bracket -std=c++14 -O2; echo "finish"; ./bracket
*/