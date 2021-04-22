#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    if(n<=3) cout<<"NO";
    else{
        cout<<"YES\n";
        if(n%2==0){
            cout<<"1 * 2 = 2\n";
            cout<<"2 * 3 = 6\n";
            cout<<"6 * 4 = 24\n";
            for(int i=5;i<=n;i+=2){
                cout<<i+1<<" - "<<i<<" = "<<1<<'\n';
                cout<<"24 * 1 = 24\n";
            }
        }
        else{
            cout<<"2 - 1 = 1\n";
            cout<<"3 + 1 = 4\n";
            cout<<"5 * 4 = 20\n";
            cout<<"20 + 4 = 24\n";
            for(int i=6;i<=n;i+=2){
                cout<<i+1<<" - "<<i<<" = "<<1<<'\n';
                cout<<"24 * 1 = 24\n";
            }
        }
    }
}
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
