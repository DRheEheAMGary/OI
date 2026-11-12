/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n;
string s;
char sufmin[N];
signed main() {
    Cios;
    // freopen("glyph.in","r",stdin);
    // freopen("glyph.out","w",stdout);
    cin>>n;
    cin>>s;
    s=s;
    sufmin[n-1]=s[n-1];
    for (int i=n-2;i>=0;i--) sufmin[i]=min(sufmin[i+1],s[i]);
    int srt=-1;
    for (int i=0;i<n;i++) {
        if (s[i]>sufmin[i]) {
            srt=i;
            break;
        }
    }
    if (srt==-1) return cout<<s<<"\n",0;
    int end=-1;
    char cmin=sufmin[srt+1];
    for (int i=n-1;i>=srt;i--) {
        if (s[i]==cmin) {
            end=i;
            break;
        } 
    }
    vector <int> idx;
    char cur=s[srt];
    idx.push_back(srt);
    for (int i=srt+1;i<end;i++) {
        if (cur<s[i]) {
            idx.push_back(i);
            cur=s[i];
        }
    }
    idx.push_back(end);
    char nw=s[idx[0]];
    for (int i=1;i<idx.size();i++) {
        char __tmp=s[idx[i]];
        s[idx[i]]=nw;
        nw=__tmp;
    }
    s[idx[0]]=nw;
    cout<<s<<"\n";
    return 0;
}

/*
g++ -g glyph.cpp -o glyph.exe -std=c++14 -O2 -static; echo "finish"; .\glyph.exe; rm glyph.exe
cd $work/ZhengRui/Competition/noip20/16/glyph && g++ glyph.cpp -o glyph -std=c++14 -O2 && echo "finish" && ./glyph && rm glyph
*/