#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+2;
void solve(){
	int n,w,wr;cin>>n>>w>>wr;
    vector<int>weight(n);
    map<int,int>mp;
    for(int& x:weight) {cin>>x;mp[x]++;}
    if(wr>=w) {cout<<"YES\n";return;}
    int maxx=wr;
    for(auto x:mp){
        maxx+=((x.second/2)*2)*x.first;
        if(maxx>=w) {cout<<"YES\n";return;}
    }
    if(maxx>=w) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main(){
    soham1192k;
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
