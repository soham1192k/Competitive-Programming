#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define carrot1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
// const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
   int n,m,x,y;cin>>n>>m>>x>>y;
   for(int i=1;i<=n;i++){
       string s;cin>>s;
       int cpyx=x;int cpyy=y;
       for(int j=0;j<s.length();j++){
           if(s[j]=='F') cpyx--;
           else if(s[j]=='P') cpyy--;
       }
       if(cpyx<=0||(cpyx==1&&cpyy<=0)) cout<<1;
       else cout<<0;
   }
   cout<<'\n';
}
int32_t main(){
    carrot1192k;
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
