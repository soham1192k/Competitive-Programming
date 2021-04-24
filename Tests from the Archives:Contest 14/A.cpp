#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pi pair<long long,long long>
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int n,k;cin>>n>>k;
    vector<int>pp(k);
    for(int& x:pp) cin>>x;
    int now=0;
    for(int i=0;i<k;i++){
        int ld=pp[i]%10;
        if(ld==0) now=(now+ld)%mod;
        else if(now==1||ld==1) now=(now+ld)%mod;
        else if(now==0) now=(now+ld)%mod;
        else now=(now*ld)%mod;
    }
    cout<<now;
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
