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
class List {
    struct listnode {
        int val;
        listnode *next,*prev;
        listnode (int _val=0) :val(_val){next=nullptr,prev=nullptr;}
    }_st;
    listnode *last=&_st;
    vector<listnode*> pool;
    listnode* newnode (int _val=0) {
        listnode* node=new listnode(_val);
        pool.push_back(node);
        return node;
    }
    public:
    ~List() {clear();}
    void clear() {
        for (auto p:pool) delete p;
        pool.clear();
        _st=listnode();
        last=&_st;
    }
    void push_back (int _val) {
        listnode* _new=newnode(_val);
        last->next=_new;
        _new->prev=last;
        last=_new;
    }
    bool make () {
        int idx=1;
        listnode *p=_st.next;
        listnode *fir=nullptr;
        while (p!=nullptr) {
            if (idx!=(p->val)) {
                fir=p;
                break;
            }
            idx++;
            p=p->next;
        }
        if (p==nullptr) return 0;
        p=_st.next;
        while (p!=nullptr) {
            if ((p->val)==idx) break;
            p=p->next;
        }
        if (p==nullptr) return 0;
        if (p==fir) return 0;
        listnode *pp=p->prev,*np=p->next;
        pp->next=np;
        if (np!=nullptr) np->prev=pp;
        listnode *fp=fir->prev;
        fp->next=p;
        p->prev=fp;
        p->next=fir;
        fir->prev=p;
        if (last==p) last=pp;
        return 1;
    }
    void output () {
        listnode *p=_st.next;
        while (p!=nullptr) {
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<"\n";
    }
    void init (int _val) {
        clear();
        listnode* node=newnode(_val);
        _st.next=node;
        node->prev=&_st;
        last=node;
    }
}li;
signed main() {
    Cios;
    int c,t;
    cin>>c>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        for (int i=1;i<=n;i++) {
            int a;
            cin>>a;
            if (i==1) li.init(a);
            else li.push_back(a);
        }
        while (k--&&li.make());
        li.output();
    }
    return 0;
}