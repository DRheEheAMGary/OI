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
intc N=1e5+10;
int n,a[N*2];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        map <int,int> mp;
        vector <int> unq;
        for (int i=1;i<=2*n;i++) {
            cin>>a[i];
            if (!mp[a[i]]) unq.push_back(a[i]);
            mp[a[i]]++;
        }
        vector <int> odd;
        int _res=0;
        for (int u:unq) {
            if (mp[u]%2==1) odd.push_back(u);
            for (int i=1;i<=mp[u]/2;i++) _res^=u;
        }
        if (odd.size()==0) cout<<(_res==0?"Menji":"Bot")<<"\n";
        else if (odd.size()==2) cout<<((odd[0]==_res||odd[1]==_res)?"Menji":"Bot")<<"\n";
        else cout<<"Bot\n";
    }
    return 0;
}