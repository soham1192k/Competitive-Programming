
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e5+10;
int digsum(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
void solve(){
    int n;cin>>n;
    while(true){
        int curr=digsum(n);
        if(__gcd(n,curr)>1){
            cout<<n<<'\n';return;
        }
        else n++;
    }
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int T=1;
    cin>>T;
    // int tc=0;
    while(T--){
        // ++tc;
        // cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
