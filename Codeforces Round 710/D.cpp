#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    map<int,int>mp;
    set<int>s;
    for(int i=0;i<n;i++){
        mp[a[i]]++;s.insert(a[i]);
    }
    priority_queue<pi>q;
    for(auto x:s){
        q.push({mp[x],x});
    }
    while(q.size()>=2){
        pi a=q.top();
        q.pop();
        pi b=q.top();
        q.pop();
        if(a.first>=2) {q.push({a.first-1,a.second});}
        if(b.first>=2) {q.push({b.first-1,b.second});}
    }
    if(q.size()==0) cout<<0<<'\n';
    else
    cout<<q.top().first<<'\n';
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
