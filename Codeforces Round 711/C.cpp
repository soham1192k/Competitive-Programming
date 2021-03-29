#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e5+10;
void solve(){
    int n,k;cin>>n>>k;
    if(n==1){
        if(k==1){
            cout<<1<<'\n';return;
        }
        else {cout<<2<<'\n';return;}
    }
    int dp[k+1][n+1];
    //FRONT
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++) dp[i][0]=1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][n-j])%mod;
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[k][n]<<'\n';
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
    // int tc=0;
    while(T--){
        // ++tc;
        // cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
