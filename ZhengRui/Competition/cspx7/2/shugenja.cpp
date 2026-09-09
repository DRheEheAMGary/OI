/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10,mod=998244353;
int n;
string s;
inline int ss (int sta,int i) {return (sta/(1ll<<i))&1;}
inline int val (char a,char b) {
    if (a=='?'&&b=='?') return 2;
    else if (a=='?'||b=='?') return 1;
    else if (a==b) return 1;
    else return 0;
}
signed main() {
    Cios;
    freopen ("shugenja.in","r",stdin);
    freopen ("shugenja.out","w",stdout);
    cin>>n;
    cin>>s;
    int res=0;
    for (int sta=0;sta<(1ll<<n);sta++) {
        string t="";
        for (int i=0;i<n;i++) {
            int _s=ss(sta,i);
            if (_s==1) t[i]='?';
            else {
                for (int j=1;i+j<n||i-j>=0;j++) {
                    if (i-j>=0&&ss(sta,i-j)==1) {
                        t[i]='L';
                        break;
                    }
                    if (i+j<n&&ss(sta,i+j)==1) {
                        t[i]='R';
                        break;
                    }
                }
            }
        }
        int pres=1;
        for (int i=0;i<n;i++) (pres*=val(s[i],t[i]))%=mod;
        (res+=pres)%=mod;
    }
    cout<<res<<"\n";
    return 0; 
}

/*
g++ -g shugenja.cpp -o shugenja.exe -O2 -std=c++14 -static ; .\shugenja.exe

3
L??

5
?LR??
*/