#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define carrot1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
map<pair<int,int>,bool>visited;
int n,m;
int rownum[4]={-1,0,0,1};
int colnum[4]={0,-1,1,0};
int cc=0;
bool ok(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void dfs(int x,int y,vector<vector<char>>&v){
    visited[{x,y}]=true;
    ++cc;
    for(int i=0;i<4;i++){
        int nr=x+rownum[i];
        int nc=y+colnum[i];
        if(ok(nr,nc)&&visited[{nr,nc}]==false&&v[nr][nc]=='1')
        dfs(nr,nc,v);
    }
}
void solve(){  
    visited.clear();
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<int>hold;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='1'&&visited[{i,j}]==false){
                cc=0;
                dfs(i,j,v);
                // cout<<cc<<'\n';
                hold.push_back(cc);
            }
        }
    }
    int sum=0;
    sort(hold.rbegin(),hold.rend());
    // for(auto x:hold) cout<<x<<" ";
    for(int i=1;i<hold.size();i+=2){
        sum+=hold[i];
    }
    cout<<sum<<'\n';
}
int32_t main(){
    carrot1192k;
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
