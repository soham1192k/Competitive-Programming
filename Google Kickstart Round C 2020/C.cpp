#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=1e4+10;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int pre[n];
    pre[0]=a[0];
    int sum=0;int cnt=0;
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==0) sum=pre[j];
            else sum=pre[j]-pre[i-1];
            int hold=(int)sqrt(sum);
            if(hold*hold==sum) cnt++;
        }
    }
    cout<<cnt<<'\n';
}       
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    cin>>T;
    int tc=0;
    while(T--){
        ++tc;
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
