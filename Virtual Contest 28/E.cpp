#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
map<int,int>mp;
void swap(vector<int>&a,int x,int y){
    x--;y--;
    assert(x>=0&&x<a.size());
    assert(y>=0&&y<a.size());
    int temp=a[x];
    mp[temp]=y+1;
    a[x]=a[y];
    mp[a[x]]=x+1;
    a[y]=temp;
}
void solve(){  
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    vector<int>primes;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(prime[i]) primes.push_back(i);
    }
    for(int i=0;i<n;i++){
        mp[a[i]]=i+1;
    }
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++){
        while(a[i-1]!=i){
            int pos=mp[i];
            int curlength=pos-i+1;
            auto itr=upper_bound(primes.begin(),primes.end(),curlength);
            itr--;
            int p=primes[itr-primes.begin()];
            // cout<<pos<<" "<<pos-p+1<<'\n';
            swap(a,pos,pos-p+1);
            v.push_back({pos,pos-p+1});
        }
    }
    cout<<v.size()<<'\n';
    for(auto x:v) cout<<min(x.first,x.second)<<" "<<max(x.first,x.second)<<'\n';
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
