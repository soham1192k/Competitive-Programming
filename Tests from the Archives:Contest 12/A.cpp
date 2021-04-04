#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
int threshold;
bool ok(int mid,vector<int>&a,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]/mid;
        if(a[i]%mid!=0) sum++;
    }
    if(sum<=threshold) return true;
    return false;
}
void solve(){   
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    cin>>threshold;
    int low=1;
    int ans=1e9;
    int high=*max_element(a.begin(),a.end());
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ok(mid,a,n)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
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
