/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int p,q,a1,a2,n,m;
class Matrix {
    public:
    int l,c,m[5][5];
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
                    __int128 _res=(res[i][j]+m[i][k]*mtx[k][j])%(::m);
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
    cin>>p>>q>>a1>>a2>>n>>m;
    Matrix A(2,2);
    A[1][1]=p,A[1][2]=q,A[2][1]=1,A[2][2]=0;
    Matrix I(1,2);
    I[1][1]=a2,I[2][1]=a1;
    if (n==1) return cout<<a1%m<<"\n",0;
    if (n==2) return cout<<a2%m<<"\n",0;
    A=qpow(A,n-2);
    I=A*I;
    cout<<I[1][1]%m<<"\n";
    return 0;
}