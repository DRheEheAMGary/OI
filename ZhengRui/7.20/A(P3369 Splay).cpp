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
class SplayTree {
    struct node{
        int s[2],fa,v,sz,cnt;
        node ()=default;
        node (int _v,int _fa):v(_v),fa(_fa) {
            sz=cnt=1;
            s[0]=s[1]=0;
        }
    }tr[N];
    int rt,idx;
    void pushup (int p) {
        tr[p].sz=tr[tr[p].s[0]].sz+tr[tr[p].s[1]].sz+tr[p].cnt;
    }
    void rotate (int u) {
        int fa=tr[u].fa,ffa=tr[fa].fa;
        int k=(tr[fa].s[1]==u);
        if (ffa) tr[ffa].s[tr[ffa].s[1]==fa]=u;
        tr[u].fa=ffa;
        tr[fa].s[k]=tr[u].s[k^1];
        if (tr[u].s[k^1]) tr[tr[u].s[k^1]].fa=fa;
        tr[u].s[k^1]=fa;
        tr[fa].fa=u;
        pushup(fa);
        pushup(u);
    }
    void splay (int u,int nrt) {
        while (tr[u].fa!=nrt) {
            int fa=tr[u].fa,ffa=tr[fa].fa;
            if (ffa!=nrt) {
                if ((tr[fa].s[1]==u)^(tr[ffa].s[1]==fa)) rotate(u);
                else rotate(fa);
            }
            rotate(u);
        }
        if (!nrt) rt=u;
    }
    void find (int v) {
        int u=rt;
        if (!u) return;
        while (tr[u].s[v>tr[u].v]&&v!=tr[u].v) u=tr[u].s[v>tr[u].v];
        splay(u,0);
    }
    public:
    void Insert (int v) {
        int u=rt,fa=0;
        while (u&&tr[u].v!=v) {
            fa=u;
            u=tr[u].s[v>tr[u].v];
        }
        if (u) tr[u].cnt++;
        else {
            u=++idx;
            if (fa) tr[fa].s[v>tr[fa].v]=u;
            tr[u]=node(v,fa);
        }
        splay(u,0);
    }
    void Delete (int v) {
        find (v);
        if (tr[rt].v!=v) return ;
        if (tr[rt].cnt>1) {
            tr[rt].cnt--;
            pushup(rt);
            return;
        }
        if (!tr[rt].s[0]&&!tr[rt].s[1]) return rt=0,void();
        if (!tr[rt].s[0]) return rt=tr[rt].s[1],tr[rt].fa=0,void();
        if (!tr[rt].s[1]) return rt=tr[rt].s[0],tr[rt].fa=0,void();
        int p=tr[rt].s[0];
        while (tr[p].s[1]) p=tr[p].s[1];
        splay(p, rt);
        tr[p].s[1]=tr[rt].s[1];
        if (tr[rt].s[1]) tr[tr[rt].s[1]].fa=p;
        rt=p;
        tr[rt].fa=0;
        pushup(rt);
    }
    int GetRank (int v) {
        find(v);
        if (tr[rt].v>=v) return tr[tr[rt].s[0]].sz+1;
        return tr[tr[rt].s[0]].sz+tr[rt].cnt+1;
    }
    int GetVal (int rk) {
        int u=rt;
        while (1) {
            int lsz=tr[tr[u].s[0]].sz;
            if (rk<=lsz) u=tr[u].s[0];
            else if (rk<=lsz+tr[u].cnt) return splay(u,0),tr[u].v;
            else rk-=lsz+tr[u].cnt,u=tr[u].s[1];
        }
    }
    int GetPrev (int v) {
        find(v);
        if (tr[rt].v<v) return tr[rt].v;
        int x=tr[rt].s[0];
        while (tr[x].s[1]) x=tr[x].s[1];
        splay(x,0);
        return tr[x].v;
    }
    int GetNext (int v) {
        find(v);
        if (tr[rt].v>v) return tr[rt].v;
        int u=tr[rt].s[1];
        while (tr[u].s[0]) u=tr[u].s[0];
        splay(u,0);
        return tr[u].v;
    }
}spl;
signed main() {
    Cios;
    int q;
    cin>>q;
    while (q--) {
        int op,x;
        cin>>op>>x;
        if (op==1) spl.Insert(x);
        if (op==2) spl.Delete(x);
        if (op==3) cout<<spl.GetRank(x);
        if (op==4) cout<<spl.GetVal(x);
        if (op==5) cout<<spl.GetPrev(x);
        if (op==6) cout<<spl.GetNext(x);
        if (op>=3) cout<<"\n";
    }
    return 0;
}
