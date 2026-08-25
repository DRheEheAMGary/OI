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
    // freopen ("test/ex_perm5.in","r",stdin);
    // freopen ("ans.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while (T--) {
        int n;
        cin>>n;
        if (n%2==0||n%4==1){
            int cnt1=1,cnt2=2;
            cout<<cnt1<<" ",cnt1+=2;
            n--;
            int idx1=0,idx2=0;
            while (n--) {
                if (idx1==2&&idx2==2) idx1=0,idx2=0;
                if (idx2<2) cout<<cnt2,cnt2+=2,idx2++;
                else cout<<cnt1,cnt1+=2,idx1++;
                cout<<" \n"[n==0];
            }
        }
        else {
            int cnt1=1,cnt2=2;
            cout<<cnt2<<" ",cnt2+=2;
            n--;
            int idx1=0,idx2=0;
            while (n--) {
                if (idx1==2&&idx2==2) idx1=0,idx2=0;
                if (idx1<2) cout<<cnt1,cnt1+=2,idx1++;
                else cout<<cnt2,cnt2+=2,idx2++;
                cout<<" \n"[n==0];
            }
        }
    }
    return 0;
}