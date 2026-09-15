// maximum sub array
// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   int n = 5;
//   int arr[5] = {1, 2, 3, 4, 5};
//   for (int start = 0; start < n; start++)
//   {
//     for (int end = start; end < n; end++)
//     {
//       for (int i = start; i <=end; i++)
//       {
//         cout << arr[i] ;
//       }
//       cout << " " ;
//     }
//     cout << endl;
//   }

//   return 0;
// }

// // maximum sub array sum
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;
// int main()
// {
//   int n = 5;

//   int arr[5] = {1, 2, 3, 4, 5};
//  int maxSum=INT_MIN;
//   for (int i = 0; i < n; i++)
//   {
//      int currSum=0;
//     for (int end = i; end < n; end++)
//     {
//       currSum +=arr[end];
//       maxSum=max( currSum,maxSum);
//     }

//   }
//   cout<<maxSum << endl;
//    return 0;
// }
// kadanes
// #include <iostream>
// #include <vector>
// #include <algorithm> // Required for max()
// #include <climits>   // Required for INT_MIN
// using namespace std;

// int main()
// {
//   // Using an array with negative numbers to show the true power of Kadane's
//   int n = 8;
//   int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};

//   int maxSum = INT_MIN; // Holds the overall maximum subarray sum found
//   int currSum = 0;       // Holds the running sum of the current subarray

//   for (int i = 0; i < n; i++)
//   {
//     // Step 1: Add the current element to our running sum
//     currSum += arr[i];

//     // Step 2: Check if the current sum is the best we've seen so far
//     maxSum = max(currSum, maxSum);

//     // Step 3: If the running sum becomes negative, throw it away!
//     // A negative sum will only decrease the value of future subarrays.
//     if (currSum < 0) {
//       currSum = 0;
//     }
//   }

//   cout << "Maximum subarray sum is: " << maxSum << endl;
//   return 0;
// }

// pair sum

// #include <iostream>
// #include <vector>
// #include <algorithm> // Required for max()
// #include <climits>   // Required for INT_MIN
// using namespace std;
// vector<int> pairSum(vector<int> nums, int target)
// {
//   vector<int> ans;
//   int n = nums.size();
//   for (int i = 0; i < n; i++)
//   {
//     for (int j = i + 1; j < n; j++)
//     {
//       if (nums[i] + nums[j] == target)
//       {
//         ans.push_back(i);
//         ans.push_back(j);
//         return ans;
//       }
//     }
//   }
//   return ans;
// }

// int main()
// {
//   vector<int> nums = {1, 2, 3, 4, 5};
//   int target = 9;
//   vector<int> ans = pairSum(nums, target);
//   cout << ans[0] << " " << ans[1] << endl;
//   return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// // Added 'const' and '&' to pass by reference for better performance
// vector<int> pairSum(const vector<int>& nums, int target){
//   vector<int> ans;
//   int n = nums.size();
//   int i = 0;
//   int j = n - 1;

//   while(i < j){
//     int pairsum = nums[i] + nums[j];

//     if(pairsum > target){
//       j--;
//     } else if(pairsum < target){
//       i++;
//     } else {
//       ans.push_back(i);
//       ans.push_back(j);
//       return ans; // FIXED: Return immediately once the pair is found
//     }
//   }

//   return ans; // FIXED: Returns an empty vector if no pair matches the target
// }

// int main()
// {
//   vector<int> nums = {1, 2, 3, 4, 5, 6};
//   int target = 11;

//   vector<int> ans = pairSum(nums, target);

//   // Safety check to prevent crashes if no pair was found
//   if(!ans.empty()) {
//     cout << "Indices: " << ans[0] << " " << ans[1] << endl;
//   } else {
//     cout << "No pair found matching the target." << endl;
//   }

//   return 0;
// }

// majority element mean element frequency greater than n/2

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// // FIXED: Changed return type from vector<int> to int
// int ME(vector<int> nums){
//   int n = nums.size();

//   for (int val : nums){
//     int freq = 0;
//     for (int el : nums){
//       if(el == val){
//         freq++;
//       }
//     }
//     if(freq > n/2){
//       return val; // Returns the individual integer
//     }
//   }

//   return -1; // FIXED: Fallback return value if no majority element exists
// }

// int main()
// {
//   vector<int> nums = {1, 2, 3, 1, 1, 1};

//   int result = ME(nums);
//   cout << "Majority Element is: " << result << endl;

//   return 0;
// }

// best optimzed way for majority element is moore vooting alg
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std; // FIXED: Added missing namespace

// int majorityElement(vector<int> nums){
//   int frq = 0;
//   int ans = 0;

//   // FIXED: Changed 'nums' to 'nums.size()'
//   for (int i = 0; i < nums.size(); i++){
//     if (frq == 0){
//       ans = nums[i];
//     }

//     if (ans == nums[i]){
//       frq++;
//     } else {
//       frq--;
//     }
//   }

//   return ans; // FIXED: Added missing return statement
// }

// int main()
// {
//   // FIXED: Removed the stray leading comma
//   vector<int> nums = {1, 2, 3, 4, 4, 4, 4, 4, 4};

//   int result = majorityElement(nums);

//   cout << "The majority element is: " << result << endl;

//   return 0;
// }

// power(x,n)  with optimzed way:binary exponentation
// #include <iostream>
// using namespace std;

// double myPow(double x, int n) {
//     double ans = 1.0;
//     long long binary = n; // Use long long to safely handle INT_MIN when inverted

//     // Handle negative exponents
//     if (binary < 0) {
//         x = 1.0 / x;
//         binary = -binary;
//     }

//     // Binary Exponentiation
//     while (binary > 0) {
//         // If the current exponent bit is odd, multiply 'x' into the answer
//         if (binary % 2 == 1) {
//             ans = ans * x;
//         }
//         // Square the base 'x' and halve the exponent
//         x = x * x;
//         binary = binary / 2;
//     }

//     return ans;
// }

// int main() {
//     double x = 2.0;
//     int n = 10;
//     cout << x << " raised to the power of " << n << " is: " << myPow(x, n) << endl;
//     return 0;
// }


// buy and stock problem
// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm>
// using namespace std;
// int main()
// {
//   int maxProfit = 0;
//   int n = 6;
//   int arr[6] = {7, 1, 5, 3, 6, 4};
//   int bestDay = arr[0];
//   for (int i=1;i<n;i++){
//     if(arr[i]>bestDay){
//       maxProfit=max(maxProfit,arr[i]-bestDay);
//     }
//     bestDay=min(bestDay,arr[i]);
//   }
//   cout<<"bestb day to but stock  = "<<maxProfit;
//   return 0;
// }


// maximum water conatain

// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm>

// using namespace std;

// int main() {
//     int width;
//     int maxwater = 0;
//     int n = 9;
//     // The array containing the heights is named 'tankline'
//     int tankline[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7}; 

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             width = j - i;
//             // FIX 1: Changed 'height' to 'tankline'
//             int ht = min(tankline[i], tankline[j]); 
//             // FIX 2: Declared 'currwater' and changed 'w' to 'width'
//             int currwater = width * ht; 
//             // FIX 3: Added missing semicolon at the end of the line
//             maxwater = max(maxwater, currwater); 
//         }
//     }

//     // Optional: Print the result to verify it works (outputs 49)
//     cout << "Max Water: " << maxwater << endl; 

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm>

// using namespace std;

// int main() {
//     int maxwater = 0;
//     int n = 9;
//     int tankline[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7}; 

//     // Initialize two pointers at the boundaries
//     int left = 0;
//     int right = n - 1;

//     while (left < right) {
//         // Calculate current width and height
//         int width = right - left;
//         int ht = min(tankline[left], tankline[right]);
        
//         // Update maximum water found so far
//         int currwater = width * ht;
//         maxwater = max(maxwater, currwater);

//         // Move the pointer that points to the shorter line
//         if (tankline[left] < tankline[right]) {
//             left++;
//         } else {
//             right--;
//         }
//     }

//     cout << "Max Water (Two-Pointer): " << maxwater << endl; 

//     return 0;
// }


// products of array except self
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n = 4;
//     int ans;
//     int arr[4] = {1, 2, 3, 4};
    
//     for(int i = 0; i < n; i++){
//         ans = 1; // Reset product multiplier to 1
//         for (int j = 0; j < n; j++){
//             if(i != j){
//                 ans *= arr[j]; // FIXED: Multiply instead of add, and use index 'j'
//             }
//         }
//         cout << ans << " "; // Added a space for cleaner output formatting
//     }
//     return 0;
// }
