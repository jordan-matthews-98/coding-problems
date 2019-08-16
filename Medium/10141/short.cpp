#include<iostream>
using namespace std;int main(){string n,N;int r,o,c=0,R;float p,P;while(cin>>r>>o,r++){while(r--)getline(cin,n);getline(cin,N);cin>>P>>R;r=R+1;while(r--)getline(cin,n);while(--o){if(getline(cin,n),cin>>p>>r,r>R||r==R&&p<P){R=r;P=p;N=n;}++r;while(r--)getline(cin,n);}if(c)cout<<'\n';cout<<"RFP #"<<++c<<'\n'<<N<<'\n';}}
