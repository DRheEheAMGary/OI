/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e3+10;
int a,b,c;
string dp[N];
bool cmp (string a,string b) {
    if (a.length()==b.length()) return a<b;
    return a.length()<b.length();
}
signed main() {
    Cios;
    // freopen("bracket.in","r",stdin);
    // freopen("bracket.out","w",stdout);
    int T;
    cin>>T;
    cin>>a>>b>>c;
    dp[1]="()";
    dp[2]="[]";
    dp[3]="{}";
    for (int i=4;i<=N;i++) {
        
    }
    return 0;
}

/*
g++ -g bracket.cpp -o bracket -std=c++14 -O2; echo "finish"; ./bracket
*/