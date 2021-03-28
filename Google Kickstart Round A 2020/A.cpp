#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n,b;cin>>n>>b;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    sort(a.begin(),a.end());
    // for(auto x:a) cout<<x<<" ";cout<<'\n';
    int curr=0;int ans=0;
    for(int i=0;i<n;i++){
        if(curr+a[i]<=b){
            curr+=a[i];
            ans++;
        }
        else break;
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
