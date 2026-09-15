// #include <iostream>
// using namespace std;

// int main() {
//     int n = 3;
//     bool isPrime = true;

//     if (n <= 1) {
//         isPrime = false;
//     } else {
//         for (int i = 2; i * i <= n; i++) {
//             if (n % i == 0) {
//                 isPrime = false;
//                 break;
//             }
//         }
//     }

//     if (isPrime) {
//         cout << n << " is a prime number." << endl;
//     } else {
//         cout << n << " is not a prime number." << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> sieveOfEratosthenes(int n) {
        // Initialize a vector of size n+1 with true
        vector<bool> isPrime(n + 1, true);

        // 0 and 1 are not prime numbers
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            // If i is prime, mark all its multiples as false
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
};

int main() {
    int n = 30;
    Solution sol;
    vector<bool> primeStatus = sol.sieveOfEratosthenes(n);

    cout << "Prime numbers up to " << n << ":" << endl;
    for (int i = 2; i <= n; i++) {
        if (primeStatus[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

// digits in number
// #include <iostream>
// #include <vector>
// using namespace std;

// int digits(int n)
// {
//   int count = 0;
//   int sum = 0;
//   while (n != 0)
//   {
//     int digits = n % 10;
//     cout << digits << endl;
//     count++;
//     sum += digits;
//     n = n / 10;
//   };
//   cout << " totoal count is  = " << count;
//   cout << " totoal sum is  = " << sum;
// }
// int main()
// {
//   int n = 1234;
//   digits(n);

//   return 0;
// }

// armstrogn number
// #include<iostream>
// using namespace std;
// bool isArmstrong(int n){
//   int copy=n;
//   int sumOfCubes=0;
//   while( n!=0){
//     int digits=n%10;
//     sumOfCubes +=(digits * digits* digits);
//     n/=10;
//   }
//   return sumOfCubes == copy;
// }

// int main(){
//   int n=153;
//   if(isArmstrong(n)){
//     cout<<n<<" is armstrong number ";
//   }else{
//     cout<<"no";
//   }

//    return 0;
// }

// // gcd
// #include <iostream>
// #include <vector>
// using namespace std;

// int gcd(int a ,int b){
//   while(a> 0 && b>0){
//     if(a>b){
//       a=a%b;
//     }else{
//       b=b%a;

//     }

//   }if (a==0) return b;
//   return a;
// }
// int main()
// {
//   int a=20;
//   int b=28;
//   cout<<gcd(a,b)<<endl;
//   return 0;
// }

// reverse a number
// #include <iostream>
// #include <vector>
// using namespace std;
// int reverse(int n)
// {
//   int revNum = 0;
//   while (n != 0)
//   {
//     int digits = n % 10;
//     revNum = revNum * 10 + digits;
//     n = n / 10;
//   }
//   return revNum;
// }
// int main()
// {
//   int n = 123;
//   cout << reverse(n);
//   return 0;
// }