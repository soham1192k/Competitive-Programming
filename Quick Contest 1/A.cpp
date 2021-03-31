#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n);
    for(int& xx:a) cin>>xx;
    int k;cin>>k;
    vector<int>b(k);
    for(int& xx:b) cin>>xx;
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    for(int i=0;i<k;i++) sum-=a[b[i]-1];
    sum++;cout<<sum;
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
