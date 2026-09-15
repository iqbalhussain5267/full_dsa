// #include<iostream>
// using namespace std;

// void fun(int i,int n){
//   if(i>n){
//     return;
//   }
//   cout<<i<<endl;
//   fun(i+1,n);
// }
// int main(){
//   int n;
//   cout<<"enter the number of terms"<<endl;
//   cin>>n;
//   fun(1,n);
// return 0;
// }

// nth fibnocii number
// #include<iostream>
// using namespace std;

// int fun(int n){
//   if(n==0 || n==1){
//     return n;
//   }
//   // cout<<i<<endl;
//   return fun(n-1) + fun(n-2);
// }
// int main(){
//   int n;
//   cout<<"enter the number of terms"<<endl;
//   cin>>n;
//   cout << fun(n) << endl;
// return 0;
// }

// factorial
// #include<iostream>
// using namespace std;
// int fact(int n){
//   if (n==0) return 1;
//    return n * fact(n-1);
// }

// int main (){
// int n;
// cout<<"enter number for factorial";
// cin>>n;
// cout<<fact(n)<<endl;

//   return 0;
// }

// #include <iostream>
// using namespace std;

// int gcd(int a, int b)
// {
//   if (b == 0)
//     return a;
//   return gcd(b, a % b);
// }
// int lcm(int a,int b){
//   return (a*b)/gcd(a,b);
// }
// int main()
// {
//   cout << "common factor is \n"<<gcd(12, 20) << endl;
//   cout<<"least common multiple is "<<lcm(12,20)<<endl;
//   return 0;
// }

// power of n
// #include <iostream>
// using namespace std;
// int main()
// {
//   int n = 90;
//   while (n % 2 == 0)
//   {
//     n = n / 2;
//   }
//   if (n == 1)
//   {
//     cout << "true";
//   }
//   else
//   {
//     cout << "no";
//   }
//   return 0;
// }

// sama problem with recursion
//  #include <iostream>
//  using namespace std;

//  int power(int n){
//   if (n==0) return false;
//   if(n==1) return true;
//   if (n%2==1) return false;
//   return power(n/2);
//  }

//  int main(){
//   int n=20;
//   cout<<power(n)<<endl;
//     return 0;
//  }

// x power n
// #include <iostream>
//  using namespace std;
//  int findpower(int x,int n){
//   if (n==0) return 1;
//   double a= findpower(x,n/2);
//   if(n%2==0) return a*a;
//   else return a*a*x;
//  }

//  int main (){
//   int n;
//   int x;
// cout<<findpower(2,4)<<endl;
//   return 0;
//  }

// #include <iostream>
// using namespace std;
// bool isprime(int n)
// {
//   if (n < 2)
//     return false;
//   for (int i = 2; i <n; i++)
//   {

//     if (n % i == 0)
//       return false;
//   }
//   return true;
// }
// int main()
// {
//   int n;
//   cout << isprime(2) << endl;

//   return 0;

// }

// finding factors of a number
// #include <iostream>
// using namespace std;

// int main(){
// int n;
// cout<<"enter a number"<<endl;
// cin>>n;
// for(int i=1;i<=n;i++){
//   if(n%i==0){
//     cout<<i<<endl;
//   }
// }
//   return 0;
// }

// merge sort

// linear search
// #include <iostream>
// using namespace std;

// int main()
// {

//   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//   int target = 13;
//   int index = -1;
//   int n = sizeof(arr) / sizeof(arr[0]);
//   for (int i = 0; i < n; i++)
//   {
//     if (arr[i] == target)
//     {
//       index = i;
//       break;
//     }
//   }
//   if (index == -1)
//   {
//     cout << "element not found" << endl;
//   }
//   else
//   {
//     cout << "element found at index " << index << endl;
//   }
//   return 0;
// }



// binary search
// #include<iostream>
// using namespace std;


// int main(){

//   int arr[]={1,2,3,4,5,6,7,8,9};
//   int n=sizeof(arr)/sizeof(arr[0]);
//   int target;
//   cout<<"enter target"<<endl;
//   cin>>target;
//   int l=0;
//   int r=n-1;
//   int index=-1;
//   while(l<=r){
//     int mid=(l+r)/2;
// if (target<arr[mid]){
//   r=mid-1;

// }else if(target>arr[mid]) {
// l=mid-1;
// }else{
//   index=mid;
//   break;
// }
//   }
//   if (index == -1)
//   {
//     cout << "element not found" << endl;
//   }
//   else
//   {
//     cout << "element found at index " << index << endl;
//   }
// return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm> // Required for std::lower_bound

int main() {
    // 1. Start with a sorted vector
    std::vector<int> vec = {10, 20, 30, 40, 50};
    int element_to_insert = 25;

    std::cout << "Original vector: ";
    for (int num : vec) std::cout << num << " ";
    std::cout << "\n";

    // 2. Use Binary Search (std::lower_bound) to find the correct position.
    // lower_bound finds the first element that is NOT less than element_to_insert.
    auto it = std::lower_bound(vec.begin(), vec.end(), element_to_insert);

    // 3. Calculate the index position (optional, for printing)
    int position = std::distance(vec.begin(), it);
    std::cout << "Binary search found correct insertion index position: " << position << "\n";

    // 4. Insert the element at that specific iterator position
    vec.insert(it, element_to_insert);

    // 5. Print the updated, still-sorted vector
    std::cout << "Vector after insertion: ";
    for (int num : vec) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
