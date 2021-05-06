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
int rownum[4]={-1,0,0,1};
int colnum[4]={0,-1,1,0};
bool ok(int nr,int nc,int n,int m){
    return nr>=0&&nr<n&&nc>=0&&nc<m;
}
void solve(){
    int n,m,w;cin>>n>>m>>w;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>v[i][j];
    }
    int dist[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dist[i][j]=1e18;
    }
    dist[0][0]=0;
    bool visited[n][m];
    memset(visited,false,sizeof(visited));
    visited[0][0]=true;
    queue<pair<int,int>>q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int>curr=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr=curr.first+rownum[i];
            int nc=curr.second+colnum[i];
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&v[nr][nc]!=-1){
                visited[nr][nc]=true;
                dist[nr][nc]=min(dist[nr][nc],dist[curr.first][curr.second]+w);
                q.push({nr,nc});
            }
        }
    }
    int minn=dist[n-1][m-1];
    int minstart=1e18;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]!=1e18&&v[i][j]!=0){
                minstart=min(minstart,v[i][j]+dist[i][j]);
            }
        }
    }
    q.push({n-1,m-1});
    memset(visited,false,sizeof(visited));
    int dist1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dist1[i][j]=1e18;
    }
    dist1[n-1][m-1]=0;
    visited[n-1][m-1]=true;
    while(!q.empty()){
        pair<int,int>curr=q.front();
        // cout<<curr.first<<" "<<curr.second<<'\n';
        q.pop();
        for(int i=0;i<4;i++){
            int nr=curr.first+rownum[i];
            int nc=curr.second+colnum[i];
            if(ok(nr,nc,n,m)&&!visited[nr][nc]&&v[nr][nc]!=-1){
                visited[nr][nc]=true;
                dist1[nr][nc]=min(dist1[nr][nc],dist1[curr.first][curr.second]+w);
                q.push({nr,nc});
            }
        }
    }
    int minend=1e18;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]!=0&&dist1[i][j]!=1e18){
                minend=min(minend,v[i][j]+dist1[i][j]);
            }
        }
    }
    int val=min(minn,minstart+minend);
    if(val>=1e16) cout<<-1;
    else cout<<val;
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
