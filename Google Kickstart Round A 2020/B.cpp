#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n,k,p;cin>>n>>k>>p;
    vector<vector<int>>v(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>v[i][j];
        }
    }
    int sum[n][k];
    for(int i=0;i<n;i++){
        sum[i][0]=v[i][0];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<k;j++){
            sum[i][j]=v[i][j]+sum[i][j-1];
        }
    }
    if(n==1){
        cout<<sum[0][p-1]<<'\n';return;
    }
    int dp[n+1][p+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=p;j++) dp[i][j]=-1e9;
    }
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            for(int how=1;how<=j;how++){
                if(how<=k)
                dp[i][j]=max(dp[i][j],dp[i-1][j-how]+sum[i-1][how-1]);
            }
        }
    }
    cout<<dp[n][p]<<'\n';
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    cin>>T;
    int tc=0;
    while(T--){
        ++tc;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
