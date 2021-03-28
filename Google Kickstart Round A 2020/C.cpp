#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
bool ok(int k,vector<int>&a,int n,int mid){
    int cnt=0;
    for(int i=1;i<n;i++){
        cnt+=(a[i]-a[i-1])/mid;
        if((a[i]-a[i-1])%mid!=0) cnt++;
        cnt--;
    }
    if(cnt<=k) return true;
    return false;
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>m(n);
    for(int& x:m) cin>>x;
    vector<int>diff;
    for(int i=1;i<n;i++){
        diff.push_back(m[i]-m[i-1]);
    }
    sort(diff.rbegin(),diff.rend());
    int ans=diff[0];
    int low=1;int high=diff[0];
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ok(k,m,n,mid)){
            ans=mid;high=mid-1;
        }
        else low=mid+1;
    }
    cout<<ans<<'\n';
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
//     #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
    int T=1;
    cin>>T;
    int tc=0;
    while(T--){
        ++tc;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
