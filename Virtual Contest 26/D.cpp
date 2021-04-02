#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n;cin>>n;
    vector<int>a(n);
    int sum=0;
    for(int& x:a) {cin>>x;sum+=x;}
    int target=sum/n;int ans=0;
    for(int i=1;i<n;i++){
        if(a[i-1]==target) ;
        else{
            ans+=abs(a[i-1]-target);
            if(a[i-1]>target){
                a[i]+=a[i-1]-target;
            }
            else{
                a[i]-=target-a[i-1];
            }
        }
    }
    cout<<ans;
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
