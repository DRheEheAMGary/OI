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
    freopen("del.in","r",stdin);
    freopen("del.out","w",stdout);
    int n;
    string s;
    cin>>n;
    cin>>s;
    bool deleted=0;
    for (int i=0;i<n;i++) {
        if (i==n-1&&!deleted) continue;
        if (s[i]>s[i+1]&&!deleted) {
            deleted=1;
            continue;
        }
        cout<<s[i];
    }
    return 0;
}

/*
g++ -g del.cpp -o del.exe -std=c++14 -O2 -static; echo "finish"; .\del.exe
*/