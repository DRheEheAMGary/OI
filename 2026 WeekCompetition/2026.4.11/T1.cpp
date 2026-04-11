/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n,a,b;
string to2 (int x) {
    string s;
    while (x) {
        s.push_back(x%2+'0');
        x/=2;
    }
    s.reserve();
    return s;
}
signed main() {
    Cios;
    cin>>n>>a>>b;
    string s=to2(n);
    auto res=s.find("1010");
    if (a==b&&res==string::npos) cout<<"YES\n";
    else cout<<"NO\n"; 
    return 0;
}