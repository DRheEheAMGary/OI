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
intc N=1e6+10;
class ACAutoMachine {
    inline int h(char c) {return c-'a';}
    struct ACAMnode {
        int son[26],fail,cnt;
        ACAMnode() =default;
        void Init() {
            memset(son,0,szof son);
            cnt=fail=0;
        } 
    }tr[N];
    int pcnt=0;
    public:
    void Init () {
        pcnt=0;
        tr[0].Init();
    }
    void Insert (char *s) {
        int u=0;
        for (int i=0;s[i];i++) {
            int &son=tr[u].son[h(s[i])];
            if (!son) son=++pcnt,tr[son].Init();
            u=son;
        }
        tr[u].cnt++;
    }
    void Build () {
        queue <int> q;
        for (int i=0;i<26;i++) {
            if (tr[0].son[i]) q.push(tr[0].son[i]);
        }
        while (!q.empty()) {
            int u=q.front();
            q.pop();
            for (int i=0;i<26;i++) {
                if (tr[u].son[i]) {
                    tr[tr[u].son[i]].fail=tr[tr[u].fail].son[i];
                    q.push(tr[u].son[i]);
                }
                else tr[u].son[i]=tr[tr[u].fail].son[i];
            }
        }
    }
    int Query (char *t) {
        int u=0,res=0;
        for (int i=0;t[i];i++) {
            u=tr[u].son[h(t[i])];
            for (int j=u;j&&tr[j].cnt!=-1;j=tr[j].fail) res+=tr[j].cnt,tr[j].cnt=-1;
        }
        return res;
    }
}acam;
int n;
char s[N];
signed main() {
    Cios;
    cin>>n;
    acam.Init();
    for (int i=1;i<=n;i++) {
        cin>>s;
        acam.Insert(s);
    }
    acam.Build();
    cin>>s;
    cout<<acam.Query(s)<<"\n";
    return 0;
}