#include <bits/stdc++.h>
using namespace std;
#define int long long
int getSum(int BITree[], int index)
{
    int sum = 0; 
    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(int BITree[], int n, int index, int val)
{
    while (index <= n) {
        BITree[index] += val;
        index += index & (-index);
    }
}
void convert(int arr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    sort(temp, temp + n);
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
    }
}
 
void findElements(int arr[], int n)
{
    convert(arr, n);
    int BIT[n + 1];
    for (int i = 1; i <= n; i++)
        BIT[i] = 0;
    int smaller_right[n], greater_left[n];
    for (int i = n - 1; i >= 0; i--) {
        smaller_right[i] = getSum(BIT, arr[i] - 1);
        updateBIT(BIT, n, arr[i], 1);
    }
    for (int i = 1; i <= n; i++)
        BIT[i] = 0;
    for (int i = 0; i < n; i++) {
        greater_left[i] = i - getSum(BIT, arr[i]);
        updateBIT(BIT, n, arr[i], 1);
    }
    int maxx=0;
    for(int i=1;i<=n-2;i++){
        maxx=max(maxx,abs(greater_left[i]-smaller_right[i]));
    }
    cout<<maxx;
}
void solve(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    findElements(a,n);
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
