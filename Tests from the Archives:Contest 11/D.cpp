#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e5+5;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int sum=0;for(int i=0;i<n;i++) sum+=a[i];
    if(sum%3!=0) {cout<<0;return;}
    int pre[n];
    pre[0]=a[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
    int target=sum/3;
    int cnt=0;int ans=0;
    for(int i=0;i<n-1;i++){
        if(pre[i]==target) cnt++;
        if(pre[i]==2*target&&pre[i]==target) ans+=cnt-1;
        else if(pre[i]==2*target) ans+=cnt;
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
}
