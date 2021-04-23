#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pi pair<long long,long long>
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int n,m;cin>>n>>m;
    vector<vector<int>>b(n,vector<int>(m));
    priority_queue<pi,vector<pi>,greater<pi>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
            q.push({b[i][j],i});
        }
    }
    vector<vector<int>>ans(n,vector<int>(m));
    // int curr=0;
    for(int i=1;i<=m;i++){
        pi cur=q.top();
        q.pop();
        ans[cur.second][i-1]=cur.first;
    }
    while(q.size()!=0){
        pi now=q.top();
        q.pop();
        int row=now.second;
        for(int j=0;j<m;j++){
            if(ans[row][j]==0){
                ans[row][j]=now.first;break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int32_t main(){
    soham1192k;
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
