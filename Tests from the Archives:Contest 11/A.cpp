#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
int x;int k;
int dp[100005][7];
int func(int pos,int lastfilled){
    if(pos==0){
        return 1;
    }
    if(dp[pos][lastfilled]!=-1) return dp[pos][lastfilled];
    int res=0;
    for(int i=1;i<=k;i++){
        if(lastfilled==0){
            res=(res+func(pos-1,i))%mod;
        }
        else{
            if(lastfilled==x){
                res=(res+func(pos-1,i))%mod;
            }
            else{
                if(i!=lastfilled) res=(res+func(pos-1,i))%mod;
            }
        }
    }
    return dp[pos][lastfilled]=res;
}
void solve(){   
    memset(dp,-1,sizeof(dp));
    int n;cin>>n>>k>>x;
    cout<<func(n,0)<<'\n';
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
