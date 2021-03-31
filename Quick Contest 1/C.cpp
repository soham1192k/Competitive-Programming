#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int a,b;cin>>a>>b;
    if(b>a){
        if(a>b-a) cout<<0;
        else cout<<b+1;
    }
    else if(b==a){
        if(b==0) cout<<1;
        else cout<<0;
    }
    else{
        if(b!=0) cout<<0;
        else cout<<2*a+1;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
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
