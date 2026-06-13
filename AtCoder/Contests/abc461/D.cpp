#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=505;
intl h,w,k,res=0;
bool mp[N][N];
int sumw[N][N];
int num[N*N];

signed main() {
    Cios;
    cin>>h>>w>>k;
    for (int i=1;i<=h;i++) {
        string s;
        cin>>s;
        for (int j=0;j<w;j++) mp[i][j+1]=s[j]-'0';
    }
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            sumw[i][j] = sumw[i][j-1] + mp[i][j];
        }
    }
    for (int i1=1;i1<=w;i1++) {
        for (int i2=i1;i2<=w;i2++) {
            num[0]=1;
            int sumsumw=0;
            for (int j=1;j<=h;j++) {
                sumsumw+=sumw[j][i2]-sumw[j][i1-1];
                if (sumsumw>=k) res+=num[sumsumw-k];
                num[sumsumw]++;
            }
            sumsumw=0;
            for (int j=1;j<=h;j++) {
                sumsumw+=sumw[j][i2]-sumw[j][i1-1];
                num[sumsumw]--; 
            }
            num[0]=0;
        }
    }
    cout<<res<<"\n";
    return 0;
}