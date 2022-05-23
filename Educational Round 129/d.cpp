#include<bits/stdc++.h>
using namespace std;
#define int long long 
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
 
map<int,int>mp;
int dig(int x){
    return 1+(int)floor(log10(x));
}
 
vector<int>split_digs(int x){
    vector<int>hold;
    while(x!=0){
        hold.push_back(x%10);
        x/=10;  
    }
    return hold;
}
 
int func(int n,int x){
    if(dig(x)==n) return 0;
    if(mp[x]!=0) return mp[x];
    int minn=1e18+10;
    vector<int>hold=split_digs(x);
    for(auto xx:hold){
        if(xx==0||xx==1) continue;
        else minn=min(minn,1+func(n,x*xx));
    }
    return mp[x]=minn;
}
 
void solve(){
    int n,x;cin>>n>>x;
    int val=func(n,x);
    if(val==1e18+10) cout<<-1;
    else cout<<func(n,x);
}  
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
