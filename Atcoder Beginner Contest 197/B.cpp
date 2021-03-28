#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int h,w,x,y;cin>>h>>w>>x>>y;
    vector<string>v(h);
    for(int i=0;i<h;i++) cin>>v[i];
    x--;y--;
    int ans=0;
    int r=x;int c=y;
    while(c>=0&&v[r][c]=='.') {ans++;c--;}
    r=x;c=y;
    while(c<w&&v[r][c]=='.') {ans++;c++;}
    r=x;c=y;
    while(r>=0&&v[r][c]=='.') {ans++;r--;}
    r=x;c=y;
    while(r<h&&v[r][c]=='.') {ans++;r++;}
    cout<<ans-3;
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
