/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<intl,intl> pii;
intc N=1e6+10;
class DS {
    priority_queue<pii> out;
    priority_queue<pii,vector<pii>,greater<pii>> in;
    pii Head,Tail;
    bool Empty=1;
    intl res=0;
    public:
    inline pii head () {return Head;}
    inline pii tail () {return Tail;}
    inline intl result () {return res;}
    inline bool empty () {return Empty;}
    void push_front (pii a,pii b) {
        if (Empty) return Head=a,Tail=b,Empty=0,res=a.first,void();
        in.push(b);
        in.push(Head);
        pii t=in.top();
        in.pop();
        out.push(t);
        res+=a.first+b.first-t.first;
        Head=a;
    }
    void push_back (pii a,pii b) {
        if (Empty) return Head=a,Tail=b,Empty=0,res=a.first,void();
        out.push(Tail);
        out.push(a);
        pii t=out.top();
        out.pop();
        in.push(t);
        res+=t.first;
        Tail=b;
    }
};
intl q,tot;
signed main() {
    Cios;
    // freopen("bracket.in","r",stdin);
    // freopen("bracket.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        DS f,g;
        cin>>q;
        tot=0;
        while (q--) {
            intl t,x,y;
            cin>>t>>x>>y;
            pii a={x,++tot},b={y,++tot};
            if (t==1) swap(a,b);
            if (f.empty()) f.push_back(a,b);
            else {
                pii hd=f.head(),tl=f.tail();
                if (t==1) f.push_front(a,b),g.push_front(b,hd);
                if (t==2) swap(f,g),f.push_front(a,hd),f.push_back(tl,b);
                if (t==3) f.push_back(a,b),g.push_back(tl,a);
            }
            cout<<f.result()<<"\n";
        }
    }
    return 0;
}

/*
g++ -g bracket.cpp -o bracket.exe -std=c++14 -O2 -static; echo "finish"; .\bracket.exe
g++  bracket.cpp -o bracket -std=c++14 -O2 && echo "finish" && ./bracket
*/