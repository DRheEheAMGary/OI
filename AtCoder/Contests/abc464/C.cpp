/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10;
int n,m,cnt=0,bkt[N];
struct event {
    int t,col,oper;
    bool operator < (const event &p) const {
        return t<p.t;
    }
};
void upd (int col,int op) {
    if (op==1) {
        if (bkt[col]==0) cnt++;
        bkt[col]++;
    }
    else if (op==-1) {
        bkt[col]--;
        if (bkt[col]==0) cnt--;
    }
}
vector <event> q;
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        int a,b,d;
        cin>>a>>d>>b;
        upd(a,1);
        q.push_back({d,a,-1});
        q.push_back({d,b,1});
    }
    sort(q.begin(),q.end());
    int nwe=0;
    for (int nw=1;nw<=m;nw++) {
        while (q[nwe].t==nw) {
            upd(q[nwe].col,q[nwe].oper);
            nwe++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}