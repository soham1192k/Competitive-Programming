
//Soham
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
const int mxN=3e5+2;
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
//***************************************************************************************************************************************************************
int dp[5001][5001];
int func(vector<int>&free,vector<int>&fill,int i,int j,int n,int m){
    if(j==m) return 0;
    else if(i>=n&&j<m) return 1e15;
    // int av=n-i;
    // int req=m-j;
    // if(av<req) return 1e17;
    //dp check
    if(dp[i][j]!=-1) return dp[i][j];
    int op1=func(free,fill,i+1,j,n,m);
    int op2=func(free,fill,i+1,j+1,n,m)+abs(fill[j]-free[i]);
    return dp[i][j]=min(op1,op2);
}
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    vector<int>fill,free;
    for(int i=0;i<n;i++){
        if(a[i]==1) fill.push_back(i+1);
        else free.push_back(i+1);
    }
    if((int)fill.size()==0) {cout<<0<<'\n';return;}
    int nn=free.size();
    int mm=fill.size();
    memset(dp,-1,sizeof(dp));
    cout<<func(free,fill,0,0,nn,mm)<<'\n';
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
