#include <bits/stdc++.h>
using namespace std;
void findParenthesis(int n,int l,int r,string p){
    if(r == n){
        cout<<p<<endl;
        return ;
    }
    if(l>r)
    findParenthesis(n,l,r+1,p+")");
    if(n > l)
    findParenthesis(n,l+1,r,p+"(");


}
int main(){
    int n;cin>>n;
    findParenthesis(n,0,0,"");
}