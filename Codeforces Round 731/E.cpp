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
 
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(k),t(k);
    map<int,int>mp;
    for(int&x:a) cin>>x;
    for(int&x:t) cin>>x;
    for(int i=0;i<k;i++) mp[a[i]]=t[i];
    vector<int>pre(n+1),suff(n+2);
    pre[0]=2e9+1;
    suff[n+1]=2e9+1;
    for(int i=1;i<=n;i++){
        if(mp[i]){
            pre[i]=min(mp[i],pre[i-1]+1);
        }
        else{
            pre[i]=pre[i-1]+1;
        }
    }
    for(int i=n;i>=1;i--){
        if(mp[i]){
            suff[i]=min(suff[i+1]+1,mp[i]);
        }
        else{
            suff[i]=suff[i+1]+1;
        }
    }
    // for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
    for(int i=1;i<=n;i++) cout<<min(pre[i],suff[i])<<" ";
    cout<<'\n';
}            
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    freopen("error.txt","w",stderr);
#endif  
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
