//soham
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
//******************************************************************************************************************************************************************
int ar[21];int k;
map<pair<pair<int,int>,pair<bool,bool>>,int>mp;
int func(int pos,int n,int currprod,bool flag,bool started){
    if(pos==n){
        if(currprod<=k&&started) return 1;
        else return 0;
    }
    if(mp.find({{pos,currprod},{flag,started}})!=mp.end()) 
    return mp[{{pos,currprod},{flag,started}}];
    int ans=0;
    if(flag){
        if(started){
            for(int i=0;i<=9;i++){
                ans+=func(pos+1,n,currprod*i,true,true);
            }
        }
        else{
            ans+=func(pos+1,n,1,true,false);
            for(int i=1;i<=9;i++){
                ans+=func(pos+1,n,currprod*i,true,true);
            }
        }
    }
    else{
        if(started){
            for(int i=0;i<ar[pos];i++){
                ans+=func(pos+1,n,currprod*i,true,true);
            }
            ans+=func(pos+1,n,currprod*ar[pos],false,true);
        }
        else{
            ans+=func(pos+1,n,1,true,false);
            for(int i=1;i<ar[pos];i++){
                ans+=func(pos+1,n,currprod*i,true,true);
            }
            ans+=func(pos+1,n,currprod*ar[pos],false,true);
        }
    }   
    return mp[{{pos,currprod},{flag,started}}]=ans;
}
void solve(){
    int n;cin>>n>>k;
    string s=to_string(n);
    int len=s.length();
    for(int i=0;i<len;i++){
        ar[i]=s[i]-'0';
    }
    cout<<func(0,len,1,false,false);
}       
int32_t main(){
    soham1192k;
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
