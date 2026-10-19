/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc Mod=1e9+7,N=205;
int n,k,m,sz;
class Matrix {
    public:
    int l,c,m[N][N];
    Matrix () =default;
    Matrix (int _l,int _c) :l(_l),c(_c) {
        memset(m,0,sizeof m);
    }
    int * operator [] (const int &idx) {return m[idx];}
    static Matrix Unit (int _n) {
        Matrix u(_n,_n);
        for (int i=1;i<=_n;i++) u[i][i]=1;
        return u;
    }
    Matrix operator * (Matrix mtx) {
        Matrix res(l,mtx.c);
        for (int i=1;i<=l;i++) {
            for (int j=1;j<=mtx.c;j++) {
                for (int k=1;k<=c;k++) {
                    __int128 _res=(res[i][j]+m[i][k]*mtx[k][j])%Mod;
                    res[i][j]=_res;
                }
            }
        }
        return res;
    }
};
Matrix qpow (Matrix m,int b) {
    int n=m.c;
    Matrix res=Matrix::Unit(n);
    while (b) {
        if (b&1) res=res*m;
        m=m*m;
        b>>=1;
    }
    return res;
}
signed main() {
    Cios;
    cin>>n>>k>>m;
    sz=k<<m;
    Matrix A(sz+1,sz+1);
    for (int i=0;i<k;i++) {
        for (int j=0;j<(1<<m);j++) {
            int msk=(j<<1)&((1<<m)-1);
            int coef=1+__builtin_popcountll(j);
            A[(i<<m)+j+1][(i<<m)+msk+1]=1;
            if (i==k-1) A[(i<<m)+j+1][sz+1]=coef;
            else A[(i<<m)+j+1][((i+1)<<m)+msk+2]=coef;
        }
    }
    A[sz+1][sz+1]=1;
    A=qpow(A,n);
    Matrix I(1,sz+1);
    I[1][1]=1;
    I=I*A;
    cout<<I[1][sz+1]<<"\n";
    return 0;
}