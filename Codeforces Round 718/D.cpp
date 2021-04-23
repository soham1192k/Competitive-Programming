#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pi pair<long long,long long>
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int n,m,k;cin>>n>>m>>k;
    if(k%2){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<-1<<" ";
            }
            cout<<'\n';
        }
        return;
    }
    vector<vector<int>>wt(n+1,vector<int>(m));
    vector<vector<int>>wt1(n,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++) cin>>wt[i][j];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++) cin>>wt1[i][j];
    }
    int dp[n+1][m+1][k/2+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int x=0;x<=k/2;x++) dp[i][j][x]=1e9;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++) dp[i][j][0]=0;
    }
    for(int x=1;x<=k/2;x++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i-1>=1)
                dp[i][j][x]=min(dp[i][j][x],dp[i-1][j][x-1]+wt1[i-1][j]);
                if(i+1<=n)
                dp[i][j][x]=min(dp[i][j][x],dp[i+1][j][x-1]+wt1[i][j]);
                if(j-1>=1)
                dp[i][j][x]=min(dp[i][j][x],dp[i][j-1][x-1]+wt[i][j-1]);
                if(j+1<=m)
                dp[i][j][x]=min(dp[i][j][x],dp[i][j+1][x-1]+wt[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<2*dp[i][j][k/2]<<" ";
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
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
