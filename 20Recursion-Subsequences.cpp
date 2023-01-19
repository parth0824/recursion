#include <bits/stdc++.h>
using namespace std;
void call(string &s,int i,string help,vector<string> &ans){
    if(i == s.size()){
        ans.push_back(help);
        return ;
    }
    call(s,i+1,help,ans);
    help.push_back(s[i]);
    call(s,i+1,help,ans);
    help.pop_back();


}
int main(){
    string s;cin>>s;
    vector<string> ans;
    call(s,0,"",ans);
    for(auto i : ans)cout<<i<<" ";
    cout<<endl<<ans.size();
return 0;
}