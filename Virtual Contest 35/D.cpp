#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
int ans=0;
void func(int a,int b){
    if(b==0) return ;
    ans+=a/b;
    func(b,a%b); 
}
void solve(){  
    int a,b;cin>>a>>b;
    if(b>a) swap(a,b);
    func(a,b);
    cout<<ans;
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
