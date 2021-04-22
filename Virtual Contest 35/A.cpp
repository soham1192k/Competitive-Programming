#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int n,a;cin>>n>>a;
    vector<int>t(n);
    for(int& x:t) cin>>x;
    a--;
    int cnt=0;
    if(t[a]==1) cnt=1;
    for(int i=1;;i++){
        int left=a-i;
        int right=a+i;
        if(left>=0&&right<n){
            if(t[left]==1&&t[right]==1) cnt+=2;
        } 
        else if(right<n&&t[right]==1) cnt++;
        else if(left>=0&&t[left]==1) cnt++;
        else if(right>=n&&left<0) break;
    }
    cout<<cnt;
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
