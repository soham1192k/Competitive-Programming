#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='*') cnt++;
    }
    if(cnt==0) {cout<<0<<'\n';return;}
    if(cnt==1) {cout<<1<<'\n';return;}
    int ans=2;
    int l=-1,f=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){
            s[i]='x';
            f=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='*'){
            s[i]='x';
            l=i;
            break;
        }
    }
    for(int i=f;i<l;i++){
        if(s[i]=='x'){
            for(int j=min(l,i+k);j>i;j--){
                if(s[j]=='*'||s[j]=='x'){
                    if(s[j]=='*')
                    ans++;
                    s[j]='x';
                    i=j-1;
                }
            }
        }
    }
    cout<<ans<<'\n';
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
    while(T--){
        solve();
    }
    return 0;
}
