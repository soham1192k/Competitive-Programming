#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    priority_queue<int,vector<int>,greater<int>>q;
    bool av[n+1];
    for(int i=1;i<=n;i++) av[i]=true;
    av[a[0]]=false;
    vector<int>minn(n);
    minn[0]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) ;
        else {minn[i]=a[i];av[a[i]]=false;}
    }
    for(int i=1;i<=n;i++) {
        if(av[i]==true)
        q.push(i);
    }
    for(int i=0;i<n;i++){
        if(minn[i]==0){
            minn[i]=q.top();
            q.pop();
        }
    }
    vector<int>maxx(n);
    for(int i=1;i<=n;i++) av[i]=true;
    av[a[0]]=false;
    maxx[0]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            ;
        }
        else {maxx[i]=a[i];av[a[i]]=false;}
    }
    vector<int>hold;
    for(int i=1;i<=n;i++){
        if(av[i]==true){
            hold.push_back(i);
        }
    }
    for(int i=1;i<n;i++){
        if(maxx[i]==0){
            auto itr=upper_bound(hold.begin(),hold.end(),a[i]);
            itr--;
            int index=itr-hold.begin();
            maxx[i]=hold[index];
            hold.erase(itr);
        }
    }
    for(auto x:minn) cout<<x<<" ";
    cout<<'\n';
    for(auto x:maxx) cout<<x<<" ";
    cout<<'\n';
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
