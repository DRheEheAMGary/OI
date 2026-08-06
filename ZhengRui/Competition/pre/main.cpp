/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const string str[13][9]={
    {},
    {"Aries","1st House","Mars","Pluto","Mars","Sun","Venus","Saturn"},
    {"Taurus","2nd House","Venus","Earth","Venus","Moon","Pluto, Mars","Uranus"},
    {"Gemini","3rd House","Mercury","Mercury","Mercury","none","Jupiter, Neptune","none"},
    {"Cancer","4th House","Moon","Moon","Moon","Jupiter","Saturn","Mars"},
    {"Leo","5th House","Sun","Sun","Sun","Pluto","Uranus","Neptune, Mercury"},
    {"Virgo","6th House","Mercury","Mercury","Mercury","Mercury","Neptune","Venus"},
    {"Libra","7th House","Venus","Venus","Venus","Saturn","Mars","Sun"},
    {"Scorpio","8th House","Mars","Pluto","Pluto","Uranus","Venus","Moon"},
    {"Sagittarius","9th House","Jupiter","Jupiter","Jupiter, Neptune","None","Mercury","Mercury"},
    {"Capricorn","10th House","Saturn","Saturn","Saturn","Mars","Moon","Jupiter"},
    {"Aquarius","11th House","Saturn","Uranus","Uranus","Neptune"," Mercury","Sun","Pluto"},
    {"Pisces","12th House","Jupiter","Neptune","Neptune","Venus","Mercury","Mercury"}
};
map<string,int> mp={{"H",1},{"RP",2},{"RB",3},{"Do",4},{"E",5},{"De",6},{"F",7}};
signed main() {
    Cios;
    int q;
    cin>>q;
    while (q--) {
        string s1,s2;
        cin>>s1>>s2;
        for (int i=1;i<=12;i++) {
            if (s1==str[i][0]) cout<<str[i][mp[s2]]<<"\n";
        }
    }
    return 0;
}