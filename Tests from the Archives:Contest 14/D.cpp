#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pi pair<long long,long long>
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
void solve(){  
    int n;cin>>n;
    vector<int>v(2*n);
    for(int i=0;i<2*n;i++) cin>>v[i];
    int maxx=1ll<<(2*n);
    map<pair<int,int>,int>mp;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){
            mp[{i,j}]=__gcd(v[i],v[j]);
        }
    }
    int dp[maxx];
    memset(dp,0,sizeof(dp));
    for(int mask=0;mask<maxx;mask++){
        for(int i=0;i<2*n;i++){
            for(int j=i+1;j<2*n;j++){
                int ith=mask&(1ll<<i);
                int jth=mask&(1ll<<j);
                if(ith==0&&jth==0){
                    int nmask=mask|(1ll<<i);
                    nmask|=(1ll<<j);
                    int roundno=__builtin_popcount(nmask);
                    dp[nmask]=max(dp[nmask],dp[mask]+(roundno/2)*mp[{i,j}]);
                }
            }
        }
    }
    cout<<dp[(1ll<<(2*n))-1];
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
