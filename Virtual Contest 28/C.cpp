#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
bool check(int n,int i){
    map<int,int>mp;
    while(n>0){
        mp[n%10]++;
        n/=10;
    }
    while(i>0){
        int d=i%10;
        i/=10;
        if(mp[d]>0) return true;
    }
    return false;
}
void solve(){  
    int x;cin>>x;int cnt=0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(check(x,i)) cnt++;
            if(i*i!=x)
            if(check(x,x/i)) cnt++; 
        }
        // cout<<i<<" "<<cnt<<'\n';
    }
    cout<<cnt;
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
