
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
int dp[1000005][2];
void solve(){   
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    sort(a.begin(),a.end());
    int maxx=0;
    for(int i=0;i<=n-3;i++){
        int sum=a[i]+a[i+1];
        auto itr=lower_bound(a.begin(),a.end(),sum);
        itr--;
        int pos=itr-a.begin();
        maxx=max(maxx,pos-i+1);
    }
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
    return 0;
}
