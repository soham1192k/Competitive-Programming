#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    vector<int>a(n);for(int& x:a) cin>>x;
    if(n==1) {cout<<a[0];return;}
    int maxx=1<<(n-1);int ans=1e9;
    for(int mask=0;mask<maxx;mask++){
        int curr=0;int final_xor=0;
        for(int i=0;i<n-1;i++){
            int bit_pos=n-2-i;
            int val=(mask&(1<<bit_pos));
            if(val!=0){
                // cout<<"1 at position:"<<i<<'\n';
                curr|=a[i];
                final_xor^=curr;
                curr=0;
            }   
            else{
                // cout<<"2 at position:"<<i<<'\n';
                curr|=a[i];
            }         
        }
        curr|=a[n-1];
        final_xor^=curr;
        // cout<<final_xor<<'\n';
        ans=min(ans,final_xor);
    }
    cout<<ans;
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
