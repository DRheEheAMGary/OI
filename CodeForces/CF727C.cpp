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
intc N=5005;
int n,a[N];
int Query (int i,int j) {
    fflush(stdout);
    cout<<"? "<<i<<" "<<j<<endl;
    fflush(stdout);
    int k;
    cin>>k;
    return k;
}
void Answer () {
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    fflush(stdout);
    exit(0);
}
signed main() {
    cin>>n;
    int a1=Query(1,2),a2=Query(2,3),a3=Query(1,3);
    a[2]=(a1+a2-a3)/2;
    a[1]=a1-a[2];
    a[3]=a2-a[2];
    for (int i=4;i<=n;i++) a[i]=Query(i-1,i)-a[i-1];
    Answer();
    return 0;
}