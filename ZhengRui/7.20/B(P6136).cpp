/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lc(p) (tr[(p)].lc)
#define rc(p) (tr[(p)].rc)
intc N=1e6+10;
mt19937 rnd(1337);
class FHQTreap {
    struct node {
        int lc,rc,v,key,sz;
    }tr[N];
    int rt,cnt=0;
    int newnode (int v) {
        tr[++cnt]={0,0,v,0,1};
        tr[cnt].key=rnd();
        return cnt;
    }
    void pushup (int p) {
        tr[p].sz=tr[lc(p)].sz+tr[rc(p)].sz+1;
    }
    void split (int p,int v,int &x,int &y) {
        if (!p) return x=y=0,void();
        if (tr[p].v<=v) {
            x=p;
            split(rc(p),v,rc(p),y);
        }
        else {
            y=p;
            split(lc(p),v,x,lc(p));
        }
        pushup(p);
    }
    int merge (int x,int y) {
        if (!x||!y) return x+y;
        if (tr[x].key>tr[y].key) {
            rc(x)=merge(rc(x),y);
            pushup(x);
            return x;
        }
        else {
            lc(y)=merge(x,lc(y));
            pushup(y);
            return y;
        }
    }
    public:
    void Insert (int v) {
        int x,y;
        split(rt,v,x,y);
        rt=merge(merge(x,newnode(v)),y);
    }
    void Delete (int v) {
        int x,y,z;
        split(rt,v,x,z);
        split(x,v-1,x,y);
        if (y) y=merge(lc(y),rc(y));
        rt=merge(merge(x,y),z);
    }
    int GetRank (int v) {
        int x,y;
        split(rt,v-1,x,y);
        int res=tr[x].sz+1;
        rt=merge(x,y);
        return res;
    } 
    int GetVal (int u,int rk) {
        while (1) {
            int lsz=tr[lc(u)].sz;
            if (rk==lsz+1) return tr[u].v;
            if (rk<=lsz) u=lc(u);
            else u=rc(u),rk-=lsz+1;
        }
    }
    int GetVal (int rk) {return GetVal(rt,rk);}
    int GetPrev (int v) {
        int x,y;
        split(rt,v-1,x,y);
        int res=GetVal(x,tr[x].sz);
        rt=merge(x,y);
        return res;
    }
    int GetNext (int v) {
        int x,y;
        split(rt,v,x,y);
        int res=GetVal(y,1);
        rt=merge(x,y);
        return res;
    }
}fhq;
signed main() {
    Cios;
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        int a;
        cin>>a;
        fhq.Insert(a);
    }
    int lst=0,res=0;
    while (m--) {
        int op,x;
        cin>>op>>x;
        x^=lst;
        if (op==1) fhq.Insert(x);
        else if (op==2) fhq.Delete(x);
        else {
            if (op==3) lst=fhq.GetRank(x);
            if (op==4) lst=fhq.GetVal(x);
            if (op==5) lst=fhq.GetPrev(x);
            if (op==6) lst=fhq.GetNext(x);
            res^=lst;
        }
    }
    cout<<res<<"\n";
    return 0;
}