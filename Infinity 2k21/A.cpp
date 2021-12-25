#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<'\n';
#else
#define debug(x)
#endif
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+1;
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//******************************************************************************************************************************************

int func(string&s,string&t){
    int n=s.length();
    int cnt=0;
    map<char,int>mp;
    mp['a']=mp['e']=mp['i']=mp['o']=mp['u']=1;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]) ;
        else if(mp[s[i]]^mp[t[i]]==1) cnt++;
        else cnt+=2;
    }
    return cnt;
}
void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    int minn=1e18;
    for(char ch='a';ch<='z';ch++){
        string cpys=s;
        string cpyt=t;
        for(int i=0;i<n;i++){
            if(cpys[i]=='?') cpys[i]=ch;
            if(cpyt[i]=='?') cpyt[i]=ch;
        }
        minn=min(minn,func(cpys,cpyt));
    }
    cout<<minn<<'\n';
}  
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
