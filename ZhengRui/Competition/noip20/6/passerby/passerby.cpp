/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,inf=1<<30;
struct point {
    int x,y,id;
}lf[N],rh[N];
int n;
struct pointCmp {
    bool operator ()(const point& a,const point& b) const {
        if (a.y!=b.y) return a.y<b.y;
        if (a.x!=b.x) return a.x<b.x;
        return a.id<b.id;
    }
};
struct rect {
    int x1,y1,x2,y2;
};
vector <rect> re;
int mch[N];
class Fenwick {
    int tr[N<<1];
    inline int lb (int x) {return x&(-x);}
    public:
    void update (int x,int k) {
        while (x<(N<<1)) {
            tr[x]+=k;
            x+=lb(x);
        }
    }
    int query (int x) {
        int res=0;
        while (x) {
            res+=tr[x];
            x-=lb(x);
        }
        return res;
    }
    int query (int l,int r) {return query(r)-query(l-1);}
}bit;
struct event {
    int x,op,y1,y2;
    bool operator <(const event &p) const {
        if (x==p.x) return op<p.op;
        return x<p.x;
    }
    event ()=default;
    event (int _x,int _op,int _y1,int _y2):x(_x),op(_op),y1(_y1),y2(_y2) {}
};
vector <event> es;
signed main() {
    Cios;
    // freopen("passerby.in","r",stdin);
    // freopen("passerby.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        lf[i]={x,y,i};
    }
    for (int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        rh[i]={x,y,i};
    }
    sort (lf+1,lf+1+n,[](const point &a,const point &b) {return a.x>b.x;});
    sort (rh+1,rh+1+n,[](const point &a,const point &b) {return a.x>b.x;});
    set<point,pointCmp> ys;
    for (int pl=1,pr=1;pl<=n;pl++) {
        while (pr<=n&&lf[pl].x<rh[pr].x) ys.insert(rh[pr]),pr++;
        auto it=ys.lower_bound({-inf,lf[pl].y,-inf});
        if (it==ys.end()) return cout<<"No\n",0;
        mch[lf[pl].id]=it->id;
        re.push_back({lf[pl].x,lf[pl].y,it->x,it->y});
        ys.erase(it);
    }
    vector <int> _uniq;
    for (auto [x1,y1,x2,y2]:re) {
        _uniq.push_back(y1);
        _uniq.push_back(y2);
    }
    sort(_uniq.begin(),_uniq.end());
    _uniq.erase(unique(_uniq.begin(),_uniq.end()),_uniq.end());
    auto getid=[&] (int y) {return lower_bound(_uniq.begin(),_uniq.end(),y)-_uniq.begin()+1;};
    for (auto [x1,y1,x2,y2]:re) {
        y1=getid(y1),y2=getid(y2);
        es.emplace_back(x1,1,y1,y2);
        es.emplace_back(x1,2,y1,y1);
        es.emplace_back(x1,2,y2,y2);
        es.emplace_back(x2,0,y1,y1);
        es.emplace_back(x2,0,y2,y2);
        es.emplace_back(x2,1,y1,y2);
    }
    sort(es.begin(),es.end());
    for (auto [x,op,y1,y2]:es) {
        if (op==0) bit.update(y1,-1);
        else if (op==2) bit.update(y1,1);
        else if (op==1) {
            if (y2-1>=y1+1&&bit.query(y1+1,y2-1)>0) return cout<<"No\n",0;
        }
    }
    cout<<"Yes\n";
    for (int i=1;i<=n;i++) cout<<mch[i]<<"\n";
    return 0;
}

/*
g++ -g passerby.cpp -o passerby.exe -std=c++14 -O2 -static; echo "finish"; .\passerby.exe; rm passerby.exe
cd $work/ZhengRui/Competition/noip20/6/passerby && g++ passerby.cpp -o passerby -std=c++14 -O2 && echo "finish" && ./passerby && rm passerby
*/