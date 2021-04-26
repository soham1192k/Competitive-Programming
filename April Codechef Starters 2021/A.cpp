#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define carrot1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int x,y,xr,yr,d;cin>>x>>y>>xr>>yr>>d;
    if(x>=xr*d&&y>=yr*d) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main(){
    carrot1192k;
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
