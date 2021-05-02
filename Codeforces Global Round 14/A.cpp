#include<bits/stdc++.h>
using namespace std;
#define int long long
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
const int mod=1e9+7;
const int mxN=105;
void solve(){
    int n,x;cin>>n>>x;int sum=0;
    vector<int>a(n);for(int& xx:a) {cin>>xx;sum+=xx;}
    if(x==sum) {cout<<"NO\n";return;}
    bool visited[n];
    memset(visited,false,sizeof(visited));int done=0;
    vector<int>hold;
    for(int i=0;i<n;i++){
        if(done+a[i]!=x) {visited[i]=true;done+=a[i];hold.push_back(a[i]);}
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) hold.push_back(a[i]); 
    }
    cout<<"YES\n";
    for(auto x:hold) cout<<x<<" ";
    cout<<'\n';
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
