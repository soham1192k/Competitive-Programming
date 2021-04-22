#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int x,y;cin>>x>>y;
    int n;cin>>n;
    if(n%6==1) cout<<(x+mod)%mod;
    else if(n%6==2) cout<<(y+mod)%mod;
    else if(n%6==3) cout<<((y-x+mod)%mod+mod)%mod;
    else if(n%6==4) cout<<(-x+mod)%mod;
    else if(n%6==5) cout<<(-y+mod)%mod;
    else cout<<((-y+x+mod)%mod+mod)%mod;
}
int32_t main(){
    soham1192k;
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
