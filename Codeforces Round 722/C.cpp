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
const int mxN=2e5+2;
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
vector<int>adj[100005];
vector<pair<int,int>>range(100005);
bool visited[100005];
int dp[100005][2];
void dfs(int src){
    dp[src][0]=dp[src][1]=0;
    visited[src]=true;
    for(auto edge:adj[src]){
        if(!visited[edge]){
            dfs(edge);
            dp[src][0]+=max(dp[edge][0]+abs(range[edge].first-range[src].first),dp[edge][1]+abs(range[edge].second-range[src].first));
            dp[src][1]+=max(dp[edge][0]+abs(range[edge].first-range[src].second),dp[edge][1]+abs(range[edge].second-range[src].second));
        }
    }
}
void solve(){
    int n;cin>>n;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        adj[i].clear();
        dp[i][0]=0;
        dp[i][1]=0;
    }
    range.clear();
    for(int i=1;i<=n;i++){
        cin>>range[i].first>>range[i].second; 
    }
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    // for(int i=1;i<=n;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<'\n';
    cout<<max(dp[1][0],dp[1][1])<<'\n';
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
