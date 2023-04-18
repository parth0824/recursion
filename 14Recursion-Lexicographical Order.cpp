#include <bits/stdc++.h>
using namespace std;
int g = 1;
void print(int &n,int help){
    if(help > n)return ;
    cout<<help<<" ";
    for(int i=0;i<10;i++){
        if(help == 0 && i == 0)i++;
        print(n,help*10+i);
    }

}
int main(){
    int n;cin>>n;
    print(n,1);
    return 0;
}