#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long INF =1000000000000;
vector<pair<int,int>>adj[100000];
void dij(int s,vector<int>&d,vector<int>&p,int n){
    d.assign(n,INF);
    p.assign(n,-1);
    d[s] = 0;
    set<pair<int,int>>q;
    q.insert({0,s});
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto edge:adj[v]){
            int to = edge.first;
            int len = edge.second;
            if(d[v] + len<d[to]){
                q.erase({d[to],to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to],to});
            }
        }
    }
}
vector<int>restore_path(int s,int t,vector<int>&p){
    vector<int>path;
    if(p[t]==-1)
    path.push_back(-1);
    else{
    for(int v= t; v!=s;v= p[v])
    path.push_back(v);
    path.push_back(s);
    reverse(path.begin(),path.end());}
    return path;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
    }
    vector<int>d;
    vector<int>p;
    dij(0,d,p,n);
    vector<int>ans = restore_path(0,n-1,p);
    if(ans.size()==1 && ans[0]==-1)
    cout<<-1;
    else{
    for(auto x:ans)
    cout<<x+1<<" ";}
}
  
