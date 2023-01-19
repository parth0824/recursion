#include <bits/stdc++.h>
using namespace std;
int e = 0;
void findsum(vector<int> &v,int fsum,int i,int sum,vector<int> help,vector<int> ans){
    if(sum == fsum){
        int y=0;e++;
        for(auto i : ans){
            if(i == 1)cout<<v[y]<<" ";
            y++;
        }
        y=0;
        cout<<"and ";
        for(auto i : ans){
            if(i == 0)cout<<v[y]<<" ";
            y++;
        }
        cout<<endl;
        return ;
    }
    if(i == v.size())return ;
    if(sum > fsum)return ;
    help.push_back(v[i]);
    ans[i]=1;
    findsum(v,fsum,i+1,v[i]+sum,help,ans);
    ans[i]=0;
    help.pop_back();
    findsum(v,fsum,i+1,sum,help,ans);
}
int main(){
    int n;cin>>n;
    vector<int> v;
    vector<int> ans;
    int sum = 0;
    for(int i=0;i<n;i++){
        int  x;cin>>x;
        sum += x;
        ans.push_back(0);
        v.push_back(x);
    }
    if(sum % 2 == 1){
        cout<<0<<endl;
        return 0;
    }
    findsum(v,sum/2,0,0,{},ans);

    cout<<e;

return 0;
}