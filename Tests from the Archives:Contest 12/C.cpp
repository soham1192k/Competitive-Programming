#include <bits/stdc++.h>
using namespace std; 
#define int long long
int Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);  
        }
    }
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
 
    return inversionCount;
}
 
// Sort array `arr[low…high]` using auxiliary array `aux`
int MergeSort(int arr[], int aux[], int low, int high)
{
    if (high == low) {        
        return 0;
    }
    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;
    inversionCount += MergeSort(arr, aux, low, mid);
    inversionCount += MergeSort(arr, aux, mid + 1, high);
    inversionCount += Merge(arr, aux, low, mid, high);
    return inversionCount;
}
 
int32_t main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int aux[n];
    for (int i = 0; i < n; i++) {
        aux[i] = arr[i];
    }
    cout<<MergeSort(arr, aux, 0, n - 1);
    return 0;
}
