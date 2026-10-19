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
intc N=200,L=1e6+10,S=N*70+10;
int n;
class ACAutoMachine {
    struct ACAMnode {
        int son[26];
        int fail,idx;
        void Init () {
            memset(son,0,szof son);
            fail=idx=0;
        }
        int& operator [] (const int &idx) {return son[idx];}
    }tr[S];
    int pidx;
    public:
    void Init () {
        pidx=0;
        tr[0].Init();
    }
    void Insert (string s,int idx) {
        int u=0;
        for (int i=0;s[i];i++) {
            int &son=tr[u][s[i]-'a'];
            if (!son) son=++pidx,tr[son].Init();
            u=son;
        }
        tr[u].idx=idx;
    }
    void Build () {
        queue <int> q;
        for (int i=0;i<26;i++) {
            if (tr[0][i]) q.push(tr[0][i]);
        }
        while (q.size()) {
            int u=q.front();
            q.pop();
            for (int i=0;i<26;i++) {
                if (tr[u].son[i]) {
                    tr[tr[u][i]].fail=tr[tr[u].fail][i];
                    q.push(tr[u][i]);
                }
                else tr[u][i]=tr[tr[u].fail][i];
            }
        }
    }
    int Query (string t,int *cnt) {
        int u=0,res=0;
        for (int i=0;t[i];i++) {
            u=tr[u][t[i]-'a'];
            for (int j=u;j;j=tr[j].fail) cnt[tr[j].idx]++;
        }
        for (int i=0;i<=pidx;i++) {
            if (tr[i].idx) res=max(res,cnt[tr[i].idx]);
        }
        return res;
    }
}acam;
string s[N],t;
int cnt[N];
signed main() {
    Cios;
    while (cin>>n&&(n!=0)) {
        acam.Init();
        for (int i=1;i<=n;i++) {
            cin>>s[i];
            acam.Insert(s[i],i);
            cnt[i]=0;
        }
        acam.Build();
        cin>>t;
        int res=acam.Query(t,cnt);
        cout<<res<<"\n";
        for (int i=1;i<=n;i++) {
            if (cnt[i]==res) cout<<s[i]<<"\n";
        }
    }
    return 0;
}