#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    int r,b,d;cin>>r>>b>>d;
    int what=min(r,b);
    r-=what;b-=what;
    int maxx=max(r,b);
    int packs=what;
    if(maxx>d*packs) cout<<"NO\n";
    else cout<<"YES\n";
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
