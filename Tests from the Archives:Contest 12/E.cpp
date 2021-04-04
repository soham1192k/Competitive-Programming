#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int cnt[100005];
    memset(cnt,0,sizeof cnt);
    for(int& x:a) {cin>>x;cnt[x]++;}
    int dp[100005];
    dp[0]=0;
    dp[1]=cnt[1];
    for(int i=2;i<=100000;i++){
        dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
    }
    int maxx=-1;
    for(int i=1;i<=100000;i++) maxx=max(maxx,dp[i]);
    cout<<maxx;
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
}
