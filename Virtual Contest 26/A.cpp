#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int curr=max(v[0].first,v[0].second);
    for(int i=1;i<n;i++){
        if(min(v[i].first,v[i].second)>curr){
            cout<<"NO";return;
        }
        else{
            if(max(v[i].first,v[i].second)<=curr)
            curr=max(v[i].first,v[i].second);
            else curr=min(v[i].first,v[i].second);
        }
    }
    cout<<"YES";
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
