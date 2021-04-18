#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){  
    int n;cin>>n;
    int r1=-1,r2=-1,c1=-1,c2=-1;
    vector<vector<char>>v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
            if(v[i][j]=='*'&&r1==-1){
                r1=i;c1=j;
            }
            else if(v[i][j]=='*'){
                r2=i;c2=j;
            }
        }
    }
    if(r1==r2){
        if(r1-1>=0){
            v[r1-1][c1]='*';v[r1-1][c2]='*';
        }
        else{
            v[r1+1][c1]='*';v[r1+1][c2]='*';
        }
    }
    else if(c1==c2){
        if(c1-1>=0){
            v[r1][c1-1]='*';
            v[r2][c1-1]='*';
        }
        else{
            v[r1][c1+1]='*';
            v[r2][c1+1]='*';
        }
    }
    else{
        //r1,c1
        //r2,c2
        //r1,c2
        //r2,c1
        v[r2][c1]='*';
        v[r1][c2]='*';
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<v[i][j];
        cout<<'\n';
    }
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
