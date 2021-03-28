#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e4+10;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    int ans=0;
    for(int& x:a) cin>>x;
    int counter=0;
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]==-1){
            counter++;
        }
        else{
            if(counter>=k-1&&a[i-1]==1){
                ans++;
            }
            counter=0;
        }
    }
    if(counter>=k-1&&a[n-1]==1) ans++;
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
