/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n;
signed main() {
    Cios;
    cin>>n;
    if (n<=4) return cout<<"-1\n",0;
    for (int i=0;i<(n+1)/2;i++) cout<<2*i+1<<" ";
    for (int i=1;i<=n/2;i++) cout<<2*i<<" ";
    cout<<"\n";
    for (int i=1;i<(n+1)/2;i++) cout<<2*i+1<<" ";
    cout<<1<<" ";
    for (int i=2;i<=n/2;i++) cout<<2*i<<" ";
    cout<<2<<"\n";
    return 0;
}

/*
g++ -g A.cpp -o A.exe -std=c++14 -O2 -static; echo "finish"; .\A.exe
cd $work/LuoguCompetition/LGR-311-Div.2 && g++  A.cpp -o A -std=c++14 -O2 && echo "finish" && ./A
*/