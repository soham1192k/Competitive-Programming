#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e5+10;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int pre[n+1];
    memset(pre,0,sizeof(pre));
    pre[0]=0;
    for(int i=1;i<=n;i++){
        char ch=s[i-1];
        pre[i]=pre[i-1]+(ch-'0');
    }
    // for(int i=0;i<=n;i++) cout<<pre[i]<<" ";
    set<int>se;
    map<int,int>mp;
    for(int i=0;i<=n;i++){
        mp[pre[i]-i]++;
        se.insert(pre[i]-i);
    }
    int ans=0;
    for(auto x:se){
        // cout<<x<<" ";
        ans+=(mp[x]*(mp[x]-1))/2;
    }
    cout<<ans<<'\n';
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
