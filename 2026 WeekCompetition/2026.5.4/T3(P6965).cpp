/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n;
vector <string> s;
vector <int> trs[N*2];
int tr[N][2];
int cnt=0;
stack <int> st;
void insert (string s,int dep) {
    if (s.size()<dep) return;
    
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        string si;
        cin>>si;
        bool fl=1;
        for (char &c:si) {
            if (c=='?') {
                c='1';
                s.push_back(si);
                c='0';
                s.push_back(si);
                c='?';
                fl=0;
                break;
            }
        }
        if (fl) s.push_back(si);
    }
    
    return 0;
}