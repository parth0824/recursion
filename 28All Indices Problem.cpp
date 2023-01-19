#include <bits/stdc++.h>
using namespace std;
void call(int *arr,int m,int i,int n,int ans){
    if(i == n)    return ;
    if(arr[i] == m)ans[i] == i;
    call(arr,m,i+1,n,ans);
}
int main(){
    int n;cin>>n;
    int arr[n];
    int ans[n];
    for(int i=0;i<n;i++){ans[i]=-1;cin>>arr[i];}
    int m;cin>>m;
    int d[5][9];
    call(arr,m,0,n,ans);
    for(int i=0;i<n;i++){
        if(ans[i] != -1)cout<<ans[i]<<" ";
    }
}