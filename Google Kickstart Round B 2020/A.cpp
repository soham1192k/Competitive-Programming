#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int ans=0;
    for(int i=1;i<=n-2;i++){
        if(a[i-1]<a[i]&&a[i]>a[i+1]) ans++;
    }
    cout<<ans<<'\n';
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    cin>>T;
    int tc=0;
    while(T--){
        ++tc;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
