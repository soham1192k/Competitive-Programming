#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+2;
void solve(){
	int n;cin>>n;
    int sum=0;
    vector<int>a(n);for(int& x:a) {cin>>x;sum+=x;}
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int query;cin>>query;
        sum=((sum*2)%mod+mod)%mod;
        cout<<sum<<'\n';
    }
}
int32_t main(){
    soham1192k;
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
