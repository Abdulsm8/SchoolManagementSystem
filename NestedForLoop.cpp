#include<iostream>
using namespace std;
int main(){
    int i,j;
    for(i=1;i<=10; i++){
    	cout<<"\n";
    	for(j=10;j>=i;j--)
    	cout<<"*";
	}
	for(i=1;i<=10; i++){
    	cout<<"\n";
    	for(j=1;j<=i;j++)
    	cout<<"*";
	}
}
