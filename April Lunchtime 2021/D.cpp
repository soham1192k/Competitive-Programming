#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+1;
vector<int>adj[mxN];
int lvl[mxN];
int chosenspecial[mxN];
bool hasspecial[mxN];
bool special[mxN];
bool visited[mxN];
int deepestspecial[mxN];
void dfs(int src,int curr_level){
    lvl[src]=curr_level;
    visited[src]=true;
    if(special[src]){
        hasspecial[src]=true;
        chosenspecial[src]=src;
    }
    for(auto edge:adj[src]){
        if(!visited[edge]){
            dfs(edge,curr_level+1);
            if(hasspecial[edge]){
                hasspecial[src]=true;
                chosenspecial[src]=chosenspecial[edge];
            }
        }
    }
}
void dfscpy(int src,int previous){
    deepestspecial[src]=previous;
    visited[src]=true;
    if(hasspecial[src]) deepestspecial[src]=src;
    for(auto edge:adj[src]){
        if(!visited[edge]) dfscpy(edge,deepestspecial[src]);
    }
}
void solve(){
	int n,k,a;cin>>n>>k>>a;
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(special,false,sizeof(special));
    memset(lvl,0,sizeof(lvl));
    memset(hasspecial,false,sizeof(hasspecial));
    memset(visited,false,sizeof(visited));
    memset(deepestspecial,0,sizeof(deepestspecial));
    memset(chosenspecial,0,sizeof(chosenspecial));
    for(int i=1;i<=k;i++){
        int p;cin>>p;special[p]=true;
    }
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[a]=true;
    dfs(a,0);
    memset(visited,false,sizeof(visited));
    visited[a]=true;
    dfscpy(a,a);
    for(int i=1;i<=n;i++){
        int dista=lvl[deepestspecial[i]];
        int distb=lvl[i]-lvl[deepestspecial[i]];
        cout<<dista-distb<<" ";
    }
    cout<<'\n';
    for(int i=1;i<=n;i++){
        cout<<chosenspecial[deepestspecial[i]]<<" ";
    }
    cout<<'\n';
}   
int32_t main(){
    soham1192k;
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
