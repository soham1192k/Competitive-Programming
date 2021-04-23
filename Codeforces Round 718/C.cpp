#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pi pair<long long,long long>
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=n-1;i>=0;i--){
        int r=i;int c=i;
        int val=a[i];
        int nr,nc;
        for(int idx=1;idx<=val;idx++){
            ans[r][c]=val;
            if(r+1<n&&ans[r+1][c]==0) {nr=r+1;nc=c;}
            else {nr=r;nc=c-1;}
            r=nr;c=nc;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
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
