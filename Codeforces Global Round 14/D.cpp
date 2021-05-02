#include<bits/stdc++.h>
using namespace std;
#define int long long
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
const int mod=1e9+7;
const int mxN=105;
void solve(){
    int n,l,r;cin>>n>>l>>r;
    vector<int>a(n);for(int& x:a) cin>>x;
    map<int,int>left,right;
    int ans=0;
    int L=l;int R=r;
    for(int i=0;i<l;i++){
        left[a[i]]++;
    }
    for(int i=l;i<n;i++){
        right[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        int now=min(left[i],right[i]);
        left[i]-=now;
        right[i]-=now;
        L-=now;
        R-=now;
    }
    if(L<R){
        swap(left,right);
        swap(L,R);
    }
    for(int i=1;i<=n;i++){
        int tot=(left[i])/2;
        int abundance=L-R;
        int do_now=min(abundance,tot*2);
        ans+=do_now/2;
        L-=do_now;
    }
    int each=(L+R)/2;
    ans+=max(L,R)-each;
    L=each;R=each;
    ans+=L;
    cout<<ans<<'\n';
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
