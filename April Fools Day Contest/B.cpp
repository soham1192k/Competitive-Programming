   #include<bits/stdc++.h>
   using namespace std;
   #define int long long 
   const int mod=1e9+7;
   const int mxN=1e6+2;
   int digsum(int n){
       int sum=0;
       while(n!=0){
           sum+=n%10;
           n/=10;
       }
       return sum;
   }
   void solve(){   
       int n;cin>>n;
       // cout<<digsum(n);
       while(n>=10){
           n=digsum(n);
       }
       cout<<n;
   }
   int32_t main(){
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);cout.tie(NULL); 
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
