#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e5+10;
void solve(){
    int n,w;cin>>n>>w;
    priority_queue<int>q;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    sort(a.rbegin(),a.rend());
    int height=0;
    for(int i=0;i<n;i++){
        if(q.size()==0){
            height++;
            if(w-a[i]!=0) q.push(w-a[i]);
        }
        else{
            if(a[i]<=q.top()){
                int curr=q.top();
                q.pop();
                if(curr-a[i]!=0) q.push(curr-a[i]);
            }
            else{
                height++;
                if(w-a[i]!=0)
                q.push(w-a[i]);
            }
        }
    }
    cout<<height<<'\n';
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
