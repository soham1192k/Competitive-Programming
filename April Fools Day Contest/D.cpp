#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n,m;cin>>n>>m;
    set<int>s;
    while(n) {
        if (!s.insert(n%m).second) {
            cout<<"NO\n";
            return;
        }
        n/= m;
    }
    cout<<"YES\n";
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
