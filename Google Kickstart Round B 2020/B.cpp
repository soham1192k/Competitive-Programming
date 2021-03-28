#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n,d;cin>>n>>d;
    vector<int>x(n);
    for(int& pp:x) cin>>pp;
    int ans=d;
    for(int i=n-1;i>=0;i--){
        ans=(ans/x[i])*x[i];
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
