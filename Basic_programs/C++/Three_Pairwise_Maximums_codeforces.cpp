/*
You are given three positive (i.e. strictly greater than zero) integers x, y and z.
Your task is to find positive integers a, b and c such that x=max(a,b), y=max(a,c) and z=max(b,c),
 or determine that it is impossible to find such a, b and c.
You have to answer t independent test cases. Print required a, b and c in any (arbitrary) order.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.
The only line of the test case contains three integers x, y, and z (1≤x,y,z≤109).

Testcase
input

5
3 2 3
100 100 100
50 49 49
10 30 20
1 1000000000 1000000000


Output

YES
3 2 1
YES
100 100 100 or 1 100 100
NO
NO
YES
1 1 1000000000



*/
// code
#include <iostream>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;
int maxi(int a, int b){
   if (a>=b)
   {
     return a;
   }
   return b;
   
}
void result (int x, int y, int z){
int a[4];
	a[0]=x;
	a[1]=y;
	a[2]=z;
	a[3]=1;
	sort(a,a+4);
		do{
		if(x==max(a[0],a[1])&&y==max(a[0],a[2])&&z==max(a[2],a[1])){
			cout<<"YES\n"<<a[0]<<' '<<a[1]<<' '<<a[2]<<"\n\n";
			return;
		}
	}while(next_permutation(a,a+4));
      printf("NO\n\n");
      return;
    
}
int main() {
  int t=0, x, y, z;
  scanf("%d", &t);
  if ( 1<= t<= 2e4)
{
for (int i = 0; i < t; i++)
{
  scanf("%d%d%d", &x, &y, &z);
  if (1<=x, y, z<=1e9)
  {
  result(x, y, z);
  }
}
  
  
}
return 0;
}