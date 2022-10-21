#include <bits/stdc++.h>
using namespace std;

void answer(int n){

    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<=j){
              cout<<"*";
			}
			else{
				cout<<" ";
			}
		}
		for(int j=1;j<=n-i;j++){
			cout<<"*";
		}
		cout<<"\n";
	}
}

int main(){
     int n;
	 cin>>n;
	 answer(n);
}