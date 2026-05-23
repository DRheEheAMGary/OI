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
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        string s;
        cin>>s;
        int c=s[0];
        if (c>='a'&&c<='c') cout<<2;
        else if (c>='d'&&c<='f') cout<<3;
        else if (c>='g'&&c<='i') cout<<4;
        else if (c>='j'&&c<='l') cout<<5;
        else if (c>='m'&&c<='o') cout<<6;
        else if (c>='p'&&c<='s') cout<<7;
        else if (c>='t'&&c<='v') cout<<8;
        else if (c>='w'&&c<='z') cout<<9;
        else cout<<"Love hanser forever!!!";
    }
    return 0;
}