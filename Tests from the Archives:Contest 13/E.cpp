#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e5+10;
void solve(){
    int k;cin>>k;
    string s;cin>>s;
    int n=s.length();
    int sum[n];
    memset(sum,0,sizeof(sum));
    if(s[0]=='1') sum[0]=1;
    for(int i=1;i<n;i++){
        if(s[i]=='1') sum[i]=1+sum[i-1];
        else sum[i]=sum[i-1];
    }
    map<int,int>cnt;
    cnt[0]=1;
    int ans=0;
    for(int i=0;i<n;i++){
        if(sum[i]>=k) 
        ans+=cnt[sum[i]-k];
        cnt[sum[i]]++;
    }       
    cout<<ans;
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
