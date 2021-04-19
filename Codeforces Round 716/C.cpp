#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    int res=n;int cpy=n;
    bool flag=false;bool oddprime=false;
    if(n==4) flag=true;
    vector<pair<int,int>>v;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int power=0;
            while(n%i==0){
                n/=i;power++;
            }
            v.push_back({i,power});
        }
    }
    if(n>1) {v.push_back({n,1});}
    sort(v.begin(),v.end());
    if(v.size()==1&&v[0].first!=2) oddprime=true;
    else if(v.size()==2&&v[0].second==1) oddprime=true;
    n=cpy;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            res-=res/i;
        }       
    }
    if(n>1) res-=res/n;
    if(flag||oddprime) cout<<res-1<<'\n'; 
    else
    cout<<res<<'\n';
    int limit=cpy-1;
    if(flag||oddprime) limit=cpy-2;
    for(int i=1;i<=limit;i++){
        if(__gcd(i,cpy)==1) cout<<i<<" ";
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
