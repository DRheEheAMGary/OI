/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n,res;
stack<pair<int,int>> st;
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int h;
        cin>>h;
        pair <int,int> p={h,1};
        while (st.size()&&(st.top().first<=h)) {
            res+=st.top().second;
            if (st.top().first==h) p.second+=st.top().second;
            st.pop();
        }
        res+=!st.empty();
        st.push(p);
    }
    cout<<res<<"\n";
    return 0;
}  