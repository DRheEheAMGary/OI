/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
#ifdef CLANGD_
#define N 10
#endif
int n,m;
struct make {
    int to,num;
};
vector <make> d[N];
bool h1[N],h2[N];
int 
signed main() {
    Cios;
    freopen("persona.in","r",stdin);
    freopen("persona.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<=n;i++) d[i].clear();
        for (int i=1;i<=m;i++) {
            int c,k;
            cin>>c>>k;
            map <int,int> tmp;
            for (int j=1;j<=k;j++) {
                string s;
                cin>>s;
                if (s=="a"||s=="b") tmp[n+(s[0]-'a'+1)]++;
                else tmp[stoi(s)]++;
            }
            for (auto var:tmp) d[var.first].push_back({c,var.second});
        }
        queue<int> q;
        q.push(n+1);
        q.push(n+2);
        h1[n+1]=1;
        h1[n+2]=1;
        while (q.size()) {
            auto u=q.front();
            q.pop();
            for (auto [c,num]:d[u]) {
                
            }
        }
    }
    return 0;
}

/*
g++ -g persona.cpp -o persona.exe -std=c++14 -O2 -static; echo "finish"; .\persona.exe
cd $work/ZhengRui/Competition/noip20/5/ g++ persona.cpp -o persona -std=c++14 -O2 && echo "finish" && ./persona
*/

