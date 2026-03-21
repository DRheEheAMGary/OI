/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=(1u<<31)-1;
int n,mind=inf,maxd=-inf,res=0;
struct stick {
    int lc,rc,type,dep;
}g[N];
void dfs (int p,int fa) {
    g[p].dep=g[fa].dep+1;
    if (g[p].lc!=-1) dfs(g[p].lc,p);
    else mind=min(mind,g[p].dep+1),maxd=max(maxd,g[p].dep+1);
    if (g[p].rc!=-1) dfs(g[p].rc,p);
    else mind=min(mind,g[p].dep+1),maxd=max(maxd,g[p].dep+1);
}
void sldfs (int p,int fa) {
    if (g[p].lc==-1&&g[p].rc==-1) {
        if (g[p].dep+1==mind) g[p].type=0;
        else g[p].type=1;
    }
    else if (g[p].lc==-1) {
        sldfs(g[p].rc,p);
        g[p].type=2;
        res++;
        swap(g[p].lc,g[p].rc);
    }
    else if (g[p].rc==-1) {
        sldfs(g[p].lc,p);
        g[p].type=2;
    }
    else {
        int &pt=g[p].type;
        int &lc=g[p].lc,&rc=g[p].rc;
        sldfs(lc,p);
        sldfs(rc,p);
        int lt=g[g[p].lc].type,rt=g[g[p].rc].type;
        if (lt==0) {
            if (rt==0) pt=0;
            else if (rt==1) pt=2,swap(lc,rc),res++;
            else if (rt==2) pt=2,swap(lc,rc),res++;
            else cout<<"?1\n";
        }
        else if (lt==1) {
            if (rt==0) pt=2;
            else if (rt==1) pt=1;
            else if (rt==2) pt=2;
            else cout<<"?2\n";
        }
        else if (lt==2) {
            if (rt==0) pt=2;
            else if (rt==1) pt=2,swap(lc,rc),res++;
            else if (rt==2) cout<<"-1\n",exit(0);
            else cout<<"?3\n";
        }
        else cout<<"?4\n";
    }
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int lc,rc;
        cin>>lc>>rc;
        g[i]={lc,rc,-1,0};
    }
    dfs(1,0);
    if (mind==maxd) {
        cout<<"0\n";
        return 0;
    }
    if (maxd-mind>1) {
        cout<<"-1\n";
        return 0;
    }
    sldfs(1,0);
    cout<<res<<"\n";
    return 0;
}