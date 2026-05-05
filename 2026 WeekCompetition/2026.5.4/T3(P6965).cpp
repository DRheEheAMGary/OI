/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10,M=3e6+10;
struct node {
    int c[2];
    vector <int> item;
}trie[N];
int cnt,tcnt=1,n;
vector <int> g[M];
void add_edge (int u,int v) {
    g[u].push_back(v);
    g[v^1].push_back(u^1);
}
void insert (string s,int id) {
    int u=1;
    for (char c:s) {
        int v=c-'0';
        if (!trie[u].c[v]) trie[u].c[v]=++tcnt;
        u=trie[u].c[v];
    }
    trie[u].item.push_back(id);
}
void build (int u,int lst) {
    int lstpre=lst;
    for (int v:trie[u].item) {
        int prev=2*(++cnt);
        add_edge(v,prev);
        if (lstpre!=-1) {
            add_edge(lstpre,v^1);
            add_edge(lstpre,prev);
        }
        lstpre=prev;
    }
    for (int i=0;i<=1;i++) {
        if (trie[u].c[i]) build(trie[u].c[i],lstpre);
    }
}
int dfn[M],low[M],bel[M],dfncnt=0,scccnt=0;
stack <int> st;
void Tarjan (int u) {
    low[u]=dfn[u]=++dfncnt;
    st.push(u);
    for (int v:g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (!bel[v]) low[u]=min(low[u],low[v]);
    }
    if (dfn[u]==low[u]) {
        scccnt++;
        while (1) {
            int v=st.top();st.pop();
            bel[v]=scccnt;
            if (u==v) break;
        }
    }
}
string s[N];
int posq[N];
signed main() {
    Cios;
    cin>>n;
    cnt=n;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
        posq[i]=-1;
        for (int j=0;j<s[i].size();j++) {
            if (s[i][j]=='?') {
                posq[i]=j;
                break;
            }
        }
        if (posq[i]==-1) {
            add_edge(2*i+1,2*i);
            insert(s[i],2*i);
        }
        else {
            s[i][posq[i]]='0';
            insert(s[i],2*i);
            s[i][posq[i]]='1';
            insert(s[i],2*i+1);
            s[i][posq[i]]='?';
        }
    }
    build (1,-1);
    for (int i=2;i<=2*cnt+1;i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i=1;i<=n;i++) {
        if (bel[2*i]==bel[2*i+1]) {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) {
        if (bel[2*i]<bel[2*i+1]) {
            if (posq[i]!=-1) s[i][posq[i]]='0';
        }
        else {
            if (posq[i]!=-1) s[i][posq[i]]='1';
        }
        cout<<s[i]<<"\n";
    }
    return 0;
}