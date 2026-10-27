/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n,m;
vector <vector<int>> pr,h0;
vector <int> up;
signed main() {
    Cios;
    freopen("utopia.in","r",stdin);
    freopen("utopia.out","w",stdout);
    cin>>n>>m;
    int all=0;
    pr.resize(n+1);
    h0.resize(m+1);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int varr;
            cin>>varr;
            all+=varr;
            if (varr) pr[i].push_back(j);
            else h0[j].push_back(i);
        }
    }
    if (all%n!=0) return cout<<"-1\n",0;
    int goal=all/n;
    int res=0;
    for (int i=1;i<=n;i++) {
        if (pr[i].size()>goal) up.push_back(i),res+=pr[i].size()-goal;
    }
    cout<<res<<"\n";
    for (auto item:up) {
        int dta=pr[item].size()-goal;
        for (auto tr:pr[item]) {
            if (!dta) break;
            if (h0[tr].empty()) continue;
            cout<<item<<" "<<h0[tr].back()<<" "<<tr<<"\n";
            h0[tr].pop_back();
            dta--;
        }
    }
    return 0;
}

/*
g++ -g utopia.cpp -o utopia.exe -std=c++14 -O2 -static; echo "finish"; .\utopia.exe
cd $work/ZhengRui/Competition/noip20/6/utopia && g++ utopia.cpp -o utopia -std=c++14 -O2 && echo "finish" && ./utopia
*/