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
int T;
intl x;
bitset<45> bx;
signed main() {
    // freopen ("test/binary/ex_binary4.in","r",stdin);
    // freopen ("ans.out","w",stdout);
    Cios;
    cin>>T;
    while (T--) {
        cin>>x;
        intl y=0;
        if (x<=1) {
            cout<<0<<"\n";
            continue;
        }
        int cnt=0;
        while (x) {
            bx[cnt]=x%2;
            x>>=1;
            cnt++;
        }
        for (int i=0;i<(cnt>>1);i++) {
            int xi=bx[i],xni=bx[cnt-i-1];
            if (xi!=xni) y+=1<<i;
        }
        cout<<y<<"\n";
    }
    return 0;
}

/*
clang++ -g binary.cpp -o binary -std=c++14 -O2 -Wall
*/