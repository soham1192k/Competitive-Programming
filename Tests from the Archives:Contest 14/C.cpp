#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pi pair<long long,long long>
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int n,k;cin>>n>>k;
    int what;cin>>what;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    if(n==1) {cout<<1;return;}
    int dp[n];
    for(int i=0;i<n;i++) dp[i]=1;
    map<int,int>mp;
    //val-->index
    mp[a[n-1]]=n;
    for(int i=n-2;i>=0;i--){
        int reqd=a[i]^k;
        if(mp[reqd]!=0){
            dp[i]=dp[mp[reqd]-1]+1;
        }
        else{
            ;
        }
        mp[a[i]]=i+1;
    }
    int maxx=0;
    for(int i=0;i<n;i++) maxx=max(maxx,dp[i]);
    cout<<maxx;
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
