/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
#include "kth.h"
int query_kth(int n_a,int n_b,int n_c,int k){
    int id[3]={0,0,0},res=-1;
    while (k) {
        int l=(k+2)/3;
        pair <int,int> tmp[3]={{get_a(id[0]+l-1),0},{get_b(id[1]+l-1),1},{get_c(id[2]+l-1),2}};
        sort(tmp,tmp+3);
        k-=l;
        id[tmp[0].second]+=l;
        res=max(res,tmp[0].first);
    }
    return res;
}
