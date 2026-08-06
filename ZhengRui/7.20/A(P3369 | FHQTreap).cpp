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
mt19937 rnd(1337);
class FHQTreap {
    struct node {
        int lc,rc,v,key,sz;
    }tp[N];
    int rt,idx;
    int newnode (int v) {
        tp[++idx]={0,0,v,0,1};
        tp[idx].key=rnd();
        return idx;
    }
    void pushup (int p) {
        tp[p].sz=tp[tp[p].lc].sz+tp[tp[p].rc].sz+1;
    }
    void split (int p,int v,int &x,int &y) {
        if (!p) {return x=y=0,void();}
        if (tp[p].v<=v) {
            x=p;
            split(tp[p].rc, v, tp[p].rc, y);
        }
        else {
            y=p;
            split(tp[p].lc, v, x, tp[p].lc);
        }
        pushup(p);
    }
    int merge (int x,int y) {
        if (!x||!y) return x+y;
        if (tp[x].key>tp[y].key) {
            tp[x].rc=merge(tp[x].rc,y);
            pushup(x);
            return x;
        }
        else {
            tp[y].lc=merge(x,tp[y].lc);
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
        if (y) y=merge(tp[y].lc,tp[y].rc);
        rt=merge(merge(x,y),z);
    }
    int GetRank (int v) {
        int x,y;
        split(rt,v-1,x,y);
        int res=tp[x].sz+1;
        rt=merge(x,y);
        return res;
    } 
    int GetVal (int p,int rk) {
        while (1) {
            int lsz=tp[tp[p].lc].sz;
            if (rk==lsz+1) return tp[p].v;
            if (rk<=lsz) p=tp[p].lc;
            else p=tp[p].rc,rk-=lsz+1;
        }
    }
    int GetVal (int rk) {return GetVal(rt,rk);}
    int GetPrev (int v) {
        int x,y;
        split(rt,v-1,x,y);
        int res=GetVal(x,tp[x].sz);
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
    int q;
    cin>>q;
    while (q--) {
        int op,x;
        cin>>op>>x;
        if (op==1) fhq.Insert(x);
        if (op==2) fhq.Delete(x);
        if (op==3) cout<<fhq.GetRank(x);
        if (op==4) cout<<fhq.GetVal(x);
        if (op==5) cout<<fhq.GetPrev(x);
        if (op==6) cout<<fhq.GetNext(x);
        if (op>=3) cout<<"\n";
    }
    return 0;
}