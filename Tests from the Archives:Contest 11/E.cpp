#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n,m;cin>>n>>m;
    vector<int>a(n),b(m);
    for(int& x:a) cin>>x;
    for(int& x:b) cin>>x;
    for(int i=0;i<512;i++){
        bool flag=true;
        for(int j=0;j<n;j++){
            bool f=false;
            for(int k=0;k<m;k++){
                if((a[j] & b[k] | i)==i){
                    f=true;break;
                }
            }
            flag=flag&&f;
        }
        if(flag) {cout<<i<<'\n';return;}
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
