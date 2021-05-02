#include<bits/stdc++.h>
using namespace std;
#define int long long
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
const int mod=1e9+7;
const int mxN=105;
void solve(){
    int n,m,x;cin>>n>>m>>x;
    vector<int>h(n);for(int& x:h) cin>>x;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++) a.push_back({h[i],i});
    sort(a.begin(),a.end());
    map<int,int>mp;
    if(m>n) {cout<<"NO\n";return;}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=0;i<m;i++){
        q.push({a[i].first,i+1});
        mp[a[i].second]=i+1;
        // cout<<mp[a[i].second]<<'\n';
    }
    for(int i=m;i<n;i++){
        pair<int,int>curr=q.top();
        q.pop();
        q.push({a[i].first+curr.first,curr.second});
        mp[a[i].second]=curr.second;
        // cout<<a[i].second<<'\n';
    }
    int maxx=-1e18;
    int minn=1e18;
    while(q.size()!=0){
        maxx=max(maxx,q.top().first);
        minn=min(minn,q.top().first);
        q.pop();
    }
    if(maxx-minn>x) {cout<<"NO\n";return;}
    cout<<"YES\n";
    for(int i=0;i<n;i++) cout<<mp[i]<<" ";
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
