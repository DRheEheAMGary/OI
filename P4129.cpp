/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m;
vector <int> g[N],ng[N];
int cnt,dfncnt=0,dfn[N],low[N],tag[N],siz[N];
stack <int> st;
void Tarjan (int u,int fa) {
    low[u]=dfn[u]=++dfncnt;
    st.push(u);
    for (int v:g[u]) {
        if (v==fa) continue;
        if (!dfn[v]) {
            Tarjan(v,u);
            if (low[v]<dfn[u]) {
                low[u]=min(low[u],low[v]);
                tag[u]++;
            }
            else if (low[v]>dfn[u]) st.pop();
            else {
                cnt++;
                siz[cnt]=1;
                while (1) {
                    int sv=st.top();
                    st.pop();
                    siz[cnt]++;
                    if (sv==v) break;
                }
            }
        }
        else if (low[v]<dfn[u]) {
            low[u]=min(low[u],dfn[v]);
            tag[u]++;
        }
    }
}
class Intl {
    int d[70005],dig=0;
    public:
    int operator [] (int idx) {return d[idx];}
    void operator *= (intl q) {
        intl tmp=0;
        for (int i=0;i<=dig;i++) {
            tmp+=d[i]*q;
            d[i]=tmp%10;
            tmp/=10;
        }
        while (tmp) {
            d[++dig]=tmp%10;
            tmp/=10;
        }
    }
    Intl (intl p) {
        dig=0;
        memset(d,0,sizeof d); 
        d[0]=p%10;
        p/=10;
        while (p) {
            d[++dig]=p%10;
            p/=10;
        }
    }
    void Output () {
        for (int i=dig;i>=0;i--) cout<<d[i];
        cout<<"\n";
    }
}res=1;
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int k,u,v;
        cin>>k>>u;
        for (int j=2;j<=k;j++) {
            cin>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            u=v;
        }
    }
    Tarjan(1,0);
    bool fl=1;
    for (int i=1;i<=n;i++) {
        if (!dfn[i]||tag[i]>=2) {
            fl=0;
            break;
        }
    }
    if (!fl) cout<<"0\n";
    else {
        for (int i=1;i<=cnt;i++) res*=(siz[i]+1);
        res.Output();
    }
    return 0;
}