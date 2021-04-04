#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
vector<pair<int,int>>adj[mxN];
vector<int>par(mxN);
vector<int>dp(mxN);
int dfs(int src,int p){
    par[src]=p;
    int res=0;
    for(int i=0;i<adj[src].size();i++){
        int edge=adj[src][i].first;
        if(edge!=par[src]){
            res+=dfs(edge,src);
        }
    }
    res++;
    dp[src]=res;
    return res;
}
void solve(){   
    int n,c,u;cin>>n>>c>>u;
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }
    par.clear();
    dp.clear();
    vector<pair<pair<int,int>,int>>v;
    for(int i=1;i<=n-1;i++){
        int a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        v.push_back({{a,b},w});
    }
    dfs(u,-1);
    priority_queue<int>q;
    for(int i=0;i<v.size();i++){
        int ff=v[i].first.first;
        int ss=v[i].first.second;
        int wei=v[i].second;
        if(par[ss]==ff){
            q.push(dp[ss]*wei);
        }
        else{
            q.push(dp[ff]*wei);
        }
    }
    for(int i=1;i<=c;i++){
        if(q.size()>=1){
            q.pop();
        }
        else{
            cout<<0<<'\n';return;
        }
    }
    int ans=0;
    while(q.size()>0){
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
