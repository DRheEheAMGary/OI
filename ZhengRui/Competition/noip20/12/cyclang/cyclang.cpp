/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,M=7,S=12;
constexpr intl inf=1ll<<60;
int n,m,sgm,s,k;
intl dta[M][S];
intl P[N][M][M],H[N][M][M],R[M],W[N];
vector <intl> F;
signed main() {
    Cios;
    cin>>n;
    cin>>m>>sgm>>s;
    cin>>k;
    for (int i=1;i<=k;i++) {
        int _f;
        cin>>_f;
        F.push_back(_f);
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=sgm;j++) cin>>dta[i][j]; 
    }
    for (int u=1;u<=m;u++) for (int v=1;v<=m;v++) P[0][u][v]=H[0][u][v]=-inf;
    for (int u=1;u<=m;u++) P[0][u][u]=0;
    for (int f:F) H[0][s][f]=0;
    W[0]=0;
    for (int i=1;i<=n;i++) {
        int u,x,w;
        cin>>u>>x>>w;
        W[i]=W[u]+w;
        for (int i1=1;i1<=m;i1++) for (int j1=1;j1<=m;j1++) P[i][i1][j1]=P[u][i1][j1];
        for (int i1=1;i1<=m;i1++) for (int j1=1;j1<=m;j1++) H[i][i1][j1]=H[u][i1][j1];
        for (int a=1;a<=m;a++) {
            for (int b=1;b<=m;b++) {
                if (P[u][a][b]>-inf/2) P[i][a][dta[b][x]]=max(P[i][a][dta[b][x]],P[u][a][b]+w);
            }
        }
        for (int c=1;c<=m;c++) {
            R[c]=-inf;
            for (int f:F) R[c]=max(R[c],P[i][c][f]);
        }
        for (int b=1;b<=m;b++) {
            for (int c=1;c<=m;c++) {
                if (H[u][b][c]>-inf/2) H[i][dta[b][x]][c]=max(H[i][dta[b][x]][c],H[u][b][c]+w);
            }
        }
        for (int c=1;c<=m;c++) {
            if (R[c]>-inf/2) H[i][s][c]=max(H[i][s][c],R[c]);
        }
        intl res=-inf;
        for (int q=1;q<=m;q++) res=max(res,H[i][q][q]);
        if (res<=-inf/2) cout<<"-1\n";
        else cout<<W[i]-res<<"\n";
    }
    return 0;
}

/*
g++ -g mainf.cpp -o mainf.exe -std=c++14 -O2 -static; echo "finish"; .\mainf.exe; rm mainf.exe
cd $work && g++ mainf.cpp -o mainf -std=c++14 -O2 && echo "finish" && ./mainf && rm mainf
*/