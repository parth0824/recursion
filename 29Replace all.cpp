// #include <iostream>
// using namespace std;
// void remove(char *a,int i)
// {
//     int j=0;
// if(a[i]=='\0'||a[i+1]=='\0')
// {
//     return;
// }
// if(a[i]=='p'&&a[i+1]=='i')
// {
//     j=i+2;
//     while(a[j]!='\0') //use this to avoid side case
//     {
//         j++;
//     }
//     while(j>=i+2)
//     {
//         a[j+2]=a[j];
//         j--;
//     }
//     a[i]='3';
//     a[i+1]='.';
//     a[i+2]='1';
//     a[i+3]='4';
//     remove(a,i+4);
// }
// remove(a,i+1);
// return;
// }
// int main() {
//     int t;
//     cin>>t;
//     char a[10000];
//     while(t--)
//     {
//     int i=0;
//     cin>>a;
//     remove(a,0);
//     cout<<a<<endl;
//     }
// return 0;
// }








#include <bits/stdc++.h>
using namespace std;
void c(string &s,string &a,int i){
    if(i == s.size())return ;
    if(i <= s.size()-2 && s[i] == 'p' && s[i+1] == 'i'){
        a += "3.14";
        i++;
    }
    else{
        a += s[i];
    }

    c(s,a,i+1);

}
void tg(){
    string s;cin>>s;
    string a = "";
    c(s,a,0);
    cout<<a<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)tg();
}