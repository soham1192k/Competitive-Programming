#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
int power(int x){
    int prod=1;
    for(int i=1;i<=x;i++) prod*=10;
    return prod;
}
void solve(){  
    int n;cin>>n;
    int cnt=0;
    for(int i=15;i>=0;i--){
        int val=205*power(i+1);
        // cout<<val<<'\n';
        while(n>=val){
            n-=val;cnt++;
        }
    }
    if(n!=0) cout<<-1<<'\n';
    else cout<<cnt<<'\n';
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
