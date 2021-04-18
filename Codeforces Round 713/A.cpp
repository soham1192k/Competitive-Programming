#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    map<int,int>mp,ind;
    for(int i=0;i<n;i++) {mp[a[i]]++;ind[a[i]]=i;}
    for(auto x:mp){
        if(x.second==1){
            cout<<ind[x.first]+1<<'\n';return;
        }
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
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
