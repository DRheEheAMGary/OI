/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=2e5+10;
int n;
class ACAutoMachine {
    struct ACAMnode {
        int son[26];
        int fail,idx,res;
        void Init () {
            memset(son,0,szof son);
            res=fail=idx=0;
        }
        int& operator [] (const int &idx) {return son[idx];}
    }tr[N];
    int pidx,tidx;
    vector <int> g[N];
    public:
    int res[N];
    void Init () {
        pidx=tidx=0;
        tr[0].Init();
    }
    void Insert (string s,int &idx) {
        int u=0;
        for (int i=0;s[i];i++) {
            int &son=tr[u][s[i]-'a'];
            if (!son) son=++pidx,tr[son].Init();
            u=son;
        }
        if (!tr[u].idx) tr[u].idx=++tidx;
        idx=tr[u].idx;
    }
    void Build () {
        queue <int> q;
        for (int i=0;i<26;i++) {
            if (tr[0][i]) q.push(tr[0][i]),g[0].push_back(tr[0][i]);
        }
        while (q.size()) {
            int u=q.front();
            q.pop();
            for (int i=0;i<26;i++) {
                if (tr[u].son[i]) {
                    tr[tr[u][i]].fail=tr[tr[u].fail][i];
                    g[tr[tr[u].fail][i]].push_back(tr[u][i]);
                    q.push(tr[u][i]);
                }
                else tr[u][i]=tr[tr[u].fail][i];
            }
        }
    }
    void Query (string t) {
        int u=0;
        for (int i=0;t[i];i++) {
            u=tr[u][t[i]-'a'];
            tr[u].res++;
        }
    }
    void dfs (int u) {
        for (int v:g[u]) {
            dfs(v);
            tr[u].res+=tr[v].res;
        }
        res[tr[u].idx]=tr[u].res;
    }
}acam;
string s,t;
int idx[N];
signed main() {
    Cios;
    cin>>n;
    acam.Init();
    for (int i=1;i<=n;i++) {
        cin>>s;
        acam.Insert(s,idx[i]);
    }
    acam.Build();
    cin>>t;
    acam.Query(t);
    acam.dfs(0);
    for (int i=1;i<=n;i++) cout<<acam.res[idx[i]]<<"\n";
    return 0;
}