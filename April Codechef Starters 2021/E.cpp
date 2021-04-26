#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int start=(a[n/2])-(k/2);
    int start1=(a[n/2-1])-(k/2);
    int ans=0;int ans1=0;
    for(int i=0;i<n;i++){
        int ending=start+k-1;
        ans+=max(abs(start-a[i]),abs(ending-a[i]));
    }
    for(int i=0;i<n;i++){
        int ending=start1+k-1;
        ans1+=max(abs(start1-a[i]),abs(ending-a[i]));
    }
    cout<<min(ans,ans1)<<'\n';
}   
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    cin>>T;
    // int tc=0;
    while(T--){
        // ++tc;
        // cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
