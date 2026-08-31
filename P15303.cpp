/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
void ask (int l,int r) {
    cout<<"? "<<l<<" "<<r<<endl;
}
int n,k,c;
int a[100005];
signed main() {
    Cios;
    cin>>n>>k>>c;
    if (k==n) {
        vector <int> _res;
        for (int i=1;i<=n;i++) {
            ask(i,i);
            int r;
            cin>>r;
            _res.push_back(r);
        }
        cout<<"! ";
        for (int r:_res) cout<<r<<" ";
        return 0;
    }
    if (c==1) {
        ask(1,n);
        int rg;
        cin>>rg;
        cout<<"! ";
        for (int i=1;i<=n;i++) {
            if (n-i+1<=rg) cout<<"1 ";
            else cout<<"0 ";
        }
        return 0;
    }
    if (c==2) {
        ask(1,n);
        int tot;
        cin>>tot;
        int nw=tot;
        int l=1,r=n;
        int id=-1;
        while (l<r&&nw==tot) {
            int mid=(l+r)>>1;
            ask(l,mid);
            int tmp;
            cin>>tmp;
            if (tmp==0) l=mid+1;
            else if (tmp==tot) r=mid;
            else id=mid,nw=tmp;
        }
        cout<<"! ";
        for (int i=1;i<=n;i++) {
            if (i<=id) {
                if (id-i+1<=nw) cout<<"1 ";
                else cout<<"0 "; 
            }
            else {
                if (i-id<=tot-nw) cout<<"1 ";
                else cout<<"0 ";
            }
        }
        return 0;
    }
    ask(1,n);
    int tot;
    cin>>tot;
    for (int i=1;i<=n;i++) {
        if (n-i+1<=tot) a[i]=1;
        else a[i]=0;
    } 
    int li=n-tot+1;
    ask(1,li-1);
    int k;
    cin>>k;
    if (tot==0||tot==n||k==0) {
        cout<<"! ";
        for (int i=1;i<=n;i++) cout<<a[i]<<" "; 
        return 0;
    }
    int l=-1,r=-1;
    int res1=0;
    if (li-k-1>=1) {
        ask(1,li-k-1);
        cin>>res1;
    }
    if (res1==0) {
        l=li-k;
        int lf=li,rg=n;
        while (lf<=rg) {
            int mid=lf+rg>>1;
            ask(li,mid);
            int tmp;
            cin>>tmp;
            if (mid-li+1-tmp==k) {
                r=mid;
                rg=mid-1;
            }
            else lf=mid+1;
        }
    }
    else {
        r=li+k-1;
        int lf=1,rg=li-1;
        while (lf<=rg) {
            int mid=lf+rg>>1;
            ask(mid,li-1);
            int tmp;
            cin>>tmp;
            if (tmp==k) {
                l=mid;
                lf=mid+1;
            }
            else rg=mid-1;
        }
    }
    reverse(a+l,a+r+1);
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}