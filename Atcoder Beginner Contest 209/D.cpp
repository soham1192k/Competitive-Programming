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
vector<int>adj[100005];
int lca[100005][21];
int d[100005];
void dfs(int src,int par,int lvl){
    lca[src][0]=par;
    d[src]=lvl;
    for(auto edge:adj[src]){
        if(edge==par) continue;
        dfs(edge,src,lvl+1);
    }
}
int leastca(int a,int b){
    if(d[a]>d[b]) swap(a,b);
    int gap=d[b]-d[a];
    while(gap>0){
        int i=(int)log2(gap);
        gap-=(1ll<<i);
        b=lca[b][i];
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(lca[a][i]!=-1&&(lca[a][i]!=lca[b][i])){
            a=lca[a][i];
            b=lca[b][i];
        }
    }
    return lca[a][0];
}
void solve(){
	int n,q;cin>>n>>q;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(lca,-1,sizeof(lca));
    dfs(1,-1,0);
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            int hold=lca[i][j-1];
            if(hold!=-1) lca[i][j]=lca[hold][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int u,v;cin>>u>>v;
        int lcancestor=leastca(u,v);
        int dist=d[u]+d[v]-2*d[lcancestor];
        if(dist%2==1) cout<<"Road\n";
        else cout<<"Town\n";
    }
}            
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    freopen("error.txt","w",stderr);
#endif  
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
