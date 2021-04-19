#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    string s;cin>>s;
    vector<int>ans(n);
    ans[0]=1;
    for(int i=1;i<n;i++){
        if(s[i]>s[i-1]) ans[i]=1+ans[i-1];
        else ans[i]=1;
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    cin>>T;
    int tc=0;
    while(T--){
        tc++;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
