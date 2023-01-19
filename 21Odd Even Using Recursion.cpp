#include <bits/stdc++.h>
using namespace std;
void call(int n){
	if(n == 0)return ;
	if(n%2 == 1)cout<<n<<endl;
	call(n-1);
	if(n%2 != 1)cout<<n<<endl;


}
int main(){
	int n;cin>>n;
	call(n);
}