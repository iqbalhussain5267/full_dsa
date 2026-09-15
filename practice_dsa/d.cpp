#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int main(){
int arr[10]={1,8,6,2,5,4,8,3,7};
int n=9;
int maxwater=0;
int left=0;
int right=n-1;
while(left<right){
  int width=right-left;
  int ht=min(arr[left],arr[right]);
  int currwater=width*ht;
  maxwater=max(maxwater,currwater);
  if(arr[left]<arr[right]){
    left++;
  }
  else{
    right--;
  }
  
}

cout<<"maxwater = "<<maxwater<<endl;
  return 0;
}
