#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    for(int i=0;i<n;i++){
        int curr=a[i];
        int sq=(int)sqrt(curr);
        if(sq*sq!=curr) {cout<<"YES\n";return;}
    }
    cout<<"NO\n";
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
