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
intc N=1e4+10;
int n,l,r;
int sg[N];
bool vis[N],stay[N];
signed main() {
    cin>>n>>l>>r;
    fill(stay,stay+n+5,1);
    if ((n-l)%2==0||l<r) {
        int y=((n-l)%2==0)?l:(l+1);
        int k=(n-y)/2;
        cout<<"First"<<endl;
        cout<<(k+1)<<" "<<y<<endl;
        while (1) {
            int a,b;
            cin>>a>>b;
            if (a<=0||b<=0) exit(0);
            int res;
            if (a<=k) res=a+k+y;
            else res=a-k-y;
            cout<<res<<" "<<b<<endl;
        }
    }
    else {
        int d=l;
        for (int _n=d;_n<=n;++_n) {
            memset(vis,0,szof vis);
            for (int a=0;a<=_n-d;a++) {
                int b=_n-d-a;
                int val=sg[a]^sg[b];
                vis[val]=1;
            }
            int mex=0;
            while (vis[mex]) mex++;
            sg[_n]=mex;
        }
        bool turn=0;
        if (sg[n]>0) cout<<"First"<<endl,turn=1;
        else cout<<"Second"<<endl;
        while (1) {
            if (turn) {
                vector <pair<int,int>> seg;
                int st=-1;
                for (int i=1;i<=n;i++) {
                    if (stay[i]) {
                        if (st==-1) st=i;
                    }
                    else {
                        if (st!=-1) {
                            seg.push_back({st,i-1});
                            st=-1;
                        }
                    }
                }
                if (st!=-1) seg.push_back({st,n});
                int tot=0;
                for (auto [s1,s2]:seg) tot^=sg[s2-s1+1];
                bool moved=0;
                for (auto [s1,s2]:seg) {
                    int len=s2-s1+1;
                    if (len<d) continue;
                    for (int a=0;a<=len-d;a++) {
                        int b=len-d-a;
                        if ((tot^sg[len]^sg[a]^sg[b])==0) {
                            int x=s1+a;
                            cout<<x<<" "<<d<<endl;
                            for (int k=x;k<x+d;k++) stay[k]=0;
                            moved=1;
                            break;
                        }
                    }
                    if (moved) break;
                }
            } 
            else {
                int a,b;
                cin>>a>>b;
                if (a<=0||b<=0) exit(0);
                for (int k=a;k<a+b;k++) stay[k]=0;
            }
            turn=!turn;
        }
    }
    return 0;
}