#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const int mxN=1e5+2;
int power(int n,int k){
    int ans=1;
    while(k>0){
        if(k%2==1){
            k--;ans=(ans*n)%mod;
        }
        else{
            k=k>>1;
            n=(n*n)%mod;
        }
    }
    return ans;
}
void solve(){  
    int n,k;cin>>n>>k;
    cout<<power(n,k)<<'\n';
}
int32_t main(){
    soham1192k;
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
