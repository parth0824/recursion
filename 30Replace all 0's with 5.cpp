#include<iostream>
using namespace std;
void call(string &n,int i){
	if(i == n.size())return ;
	if(n[i] == '0')n[i]='5';
	call(n,i+1);
}
int main () {
	string n;cin>>n;
	call(n,0);
	cout<<n;
	return 0;
}