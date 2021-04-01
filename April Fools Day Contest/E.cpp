#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
int h,w;
pair<int,int> getclosest(vector<vector<char>>&v,int r,int c){
    int minn=1e9;int maxr=-1;int maxc=-1;
    for(int i=r;i<h;i++){
        for(int j=c;j<w;j++){
            if(i==r&&j==c) continue;
            if(v[i][j]=='*'){
                if(minn>abs(i-r)+abs(j-c)){
                    minn=abs(i-r)+abs(j-c);
                    maxr=i;maxc=j;
                }
                else if(minn==abs(i-r)+abs(j-c)){
                    if(maxc<j){
                        maxr=i;maxc=j;
                    }
                }
            }
        }
    }
    // cout<<maxr<<" "<<maxc<<'\n';
    return {maxr,maxc};
}
void solve(){   
    cin>>h>>w;
    vector<vector<char>>v(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>v[i][j];
        }
    }
    int r=0,c=0;int cnt=0;
    if(v[0][0]=='*') cnt++;
    while(true){
        pair<int,int>close=getclosest(v,r,c);
        r=close.first;c=close.second;
        if(r==-1&&c==-1) break;
        cnt++;
        // cout<<r<<" "<<c<<'\n';
    }
    cout<<cnt;
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
