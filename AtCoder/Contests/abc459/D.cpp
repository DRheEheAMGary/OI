/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int T;
string s;
map <char,int> mp;
vector <char> unuse;
signed main() {
    Cios;
    cin>>T;
    while (T--) {
        cin>>s;
        mp.clear();
        unuse.clear();
        int mxcnt=-1;
        char mxc='~';
        for (char c:s) {
            mp[c]++;
            if (mp[c]>mxcnt) {
                mxcnt=mp[c];
                mxc=c;
            }
        }
        if (mxcnt>(s.size()+1)/2) {
            cout<<"No\n";
            continue;
        }
        for (char c:s) {
            if (c!=mxc) unuse.push_back(c);
        }
        
    }
    return 0;
}