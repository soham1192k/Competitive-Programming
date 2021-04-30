#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++) cin>>b[i];
    int total=0;
    for(int i=0;i<n;i++) total+=a[i]*b[i];
    vector<vector<int>>dp(n,vector<int>(n));
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i=0;i<n-1;i++){
        dp[i][i+1]=a[i]*b[i+1]+a[i+1]*b[i]-a[i]*b[i]-a[i+1]*b[i+1];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<n;j++){
            dp[i][j]=a[i]*b[j]+a[j]*b[i]-a[i]*b[i]-a[j]*b[j]+dp[i+1][j-1];
        }
    }
    int maxx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) maxx=max(maxx,dp[i][j]);
    }
    if(maxx<0) cout<<total<<'\n';
    else cout<<total+maxx<<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
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
