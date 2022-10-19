#include<iostream>
using namespace std;
#include<vector>

 void bubblesort(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        bool swaped=false;
        for(int j=0; j<arr.size()-i-1; j++){
            if(arr[j]>arr[j+1]){
                swaped=true;
                int t=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=t;
            }
        }
        if( swaped==false){
            break;
        }
 }
 for(int ele:arr){
    cout<<ele<<" ";
 }

 }
 int main(){
    vector<int>arr={1,34,8,7,9,5,0,13};
    bubblesort(arr);
    return 0;
 }
    



