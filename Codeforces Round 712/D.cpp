#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){   
    int n;cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2==1) v[i][j]=2;
            else v[i][j]=1;
        }
    }
    vector<pair<int,int>>one,two;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1){
                one.push_back({i,j});
            }
            else{
                two.push_back({i,j});
            }
        }
    }
    int posone=0;int postwo=0;
    for(int x=1;x<=n*n;x++){
        int choice;cin>>choice;
        if(choice==1){
            if(postwo<two.size()){
                cout<<2<<" "<<two[postwo].first+1<<" "<<two[postwo].second+1<<endl;
                postwo++;
            }
            else{
                cout<<3<<" "<<one[posone].first+1<<" "<<one[posone].second+1<<endl;
                posone++;
            }
        }
        else if(choice==2){
            if(posone<one.size()){
                cout<<1<<" "<<one[posone].first+1<<" "<<one[posone].second+1<<endl;
                posone++;
            }
            else{
                cout<<3<<" "<<two[postwo].first+1<<" "<<two[postwo].second+1<<endl;
                postwo++;
            }
        }
        else{
            if(posone<one.size()){
                cout<<1<<" "<<one[posone].first+1<<" "<<one[posone].second+1<<endl;
                posone++;
            }
            else{
                cout<<2<<" "<<two[postwo].first+1<<" "<<two[postwo].second+1<<endl;
                postwo++;
            }
        }
    }
    return;
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
