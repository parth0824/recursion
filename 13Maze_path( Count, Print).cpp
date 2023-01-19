#include <bits/stdc++.h>
using namespace std;
void findPath(int &n,int &m,int i,int j,string help,vector<string> &ans){
    if(i == n || j == m)return ;
    if(i == n-1 && j == m-1){
        ans.push_back(help);
    }
    findPath(n,m,i+1,j,help+"V",ans);
    findPath(n,m,i,j+1,help+"H",ans);
}
int main(){
    int n,m;cin>>n>>m;
    vector<string> ans;
    findPath(n,m,0,0,"",ans);
    for(auto i : ans)cout<<i<<" ";
    cout<<endl<<ans.size();
    return 0;

}