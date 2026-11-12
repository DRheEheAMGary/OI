/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
signed main() {
    Cios;
    freopen("lucky.in","r",stdin);
    freopen("lucky.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        string s;
        cin>>s;
        bool fl=1;
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i]!='9') {
                s[i]++;
                fl=0;
                break;
            }
        }
        if (fl) s='1'+s;
        cout<<s<<"\n";
    }
    return 0;
}

/*
g++ -g lucky.cpp -o lucky.exe -std=c++14 -O2 -static; echo "finish"; .\lucky.exe; rm lucky.exe
cd $work/ZhengRui/Competition/noip20/15/lucky && g++ lucky.cpp -o lucky -std=c++14 -O2 && echo "finish" && ./lucky && rm lucky
*/