/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
signed main() {
    Cios;
    char c;
    string s;
    string s_;
    getline(cin,s_);
    c=s_[0];
    getline(cin,s);
    bool new_word=0,numbered=0;
    int cnt=0;
    for (char si:s) {
        if (si!=' ') {
            if (!new_word) {
                new_word=1;
                numbered=0;
            }
            if (!numbered&&si==c) {
                cnt++;
                numbered=1;
            }
        }
        else new_word=0;
    }
    cout<<cnt;
    return 0;
}