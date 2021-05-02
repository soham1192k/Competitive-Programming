#include<bits/stdc++.h>
using namespace std;
#define int long long
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
const int mod=1e9+7;
const int mxN=105;
void solve(){
    int n;cin>>n;
    //n/2 should be perfect sq
    //n/4 should be perfect sq
    int a=(int)sqrt(n/2);
    if(n%2==0&&a*a==n/2) {cout<<"YES\n";return;}
    int b=(int)sqrt(n/4);
    if(n%4==0&&b*b==n/4) {cout<<"YES\n";return;}
    cout<<"NO\n";
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
