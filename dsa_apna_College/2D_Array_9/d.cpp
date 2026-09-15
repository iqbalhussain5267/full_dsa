// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   int matrix[4][3] = {{1, 2, 3}, {2, 3, 3}, {4, 5, 6}, {7, 8, 90}};
//   int rows = 4;
//   int cols = 3;
//   // cout << matrix[3][2];
//   for (int i = 0; i < rows; i++)
//   {
//     for (int j = 0; j < cols; j++)
//     {
//       cout << matrix[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
//   return 0;
// }

// take input
// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   int matrix[4][3] = {{1, 2, 3}, {2, 3, 3}, {4, 5, 6}, {7, 8, 90}};
//   int rows = 4;
//   int cols = 3;
//   // cout << matrix[3][2];
//   // input
//   cout << "enter four row every row contain 3 cols ";
//   for (int i = 0; i < rows; i++)
//   {
//     for (int j = 0; j < cols; j++)
//     {
//       cin >> matrix[i][j];
//     }
//   }
//   // ouput
//   for (int i = 0; i < rows; i++)
//   {
//     for (int j = 0; j < cols; j++)
//     {
//       cout << matrix[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
//   return 0;
// }

// // linear search
// #include<iostream>
// using namespace std;
// bool linearsearch(int matrix[][3],int rows,int cols,int target){

//   for (int i=0;i<rows;i++){
//     for(int j=0;j<cols;j++){
//       if(matrix[i][j]==target){
//         return 1;

//       }

//     }
//   }
// return 0;
// }

// int main(){

// int matrix[2][3]={{1,2,3},{4,9,6}};
// int rows=2;
// int cols=3;
// int target=1;
// cout<<linearsearch(matrix,rows,cols,target);
//   return 0;
// }

// print that array /row which has maxsum
// #include <iostream>
// #include <vector>
// #include <climits> // Required for INT_MIN

// using namespace std;

// void printMaxSumRow(int matrix[][3], int rows, int cols) {
//     int maxRowSum = INT_MIN;
//     int maxRowIndex = -1;

//     // Find the row with the maximum sum
//     for (int i = 0; i < rows; i++) {
//         int rowSum = 0;
//         for (int j = 0; j < cols; j++) {
//             rowSum += matrix[i][j];
//         }

//         if (rowSum > maxRowSum) {
//             maxRowSum = rowSum;
//             maxRowIndex = i;
//         }
//     }

//     // Print the row that has the maximum sum
//     cout << "Row with max sum (Index " << maxRowIndex << "): ";
//     for (int j = 0; j < cols; j++) {
//         cout << matrix[maxRowIndex][j] << " ";
//     }
//     cout << "\nMaximum Sum: " << maxRowSum << endl;
// }

// int main() {
//     int matrix[2][3] = {{1, 2, 3}, {3, 4, 3}};
//     int rows = 2;
//     int cols = 3;

//     printMaxSumRow(matrix, rows, cols);

//     return 0;
// }

// max diogonal sum
// #include <iostream>
// #include <vector>
// using namespace std;
// int diogonal(int matrix[][4],int n){
//   int sum=0;
// for (int i=0;i<n;i++){
//   for(int j=0; j<n;j++){
//     if(i==j){
//       sum +=matrix[i][j];

//     }else if(j ==n-1-i){
// sum +=matrix[i][j];
//     }
//   }
// }
// return sum;
// }
// int main()
// {
//   int matrix[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//   int n=4;
//   cout<<diogonal(matrix,n);
//   return 0;
// }

// binary search in 2d array
#include <iostream>
#include <vector>

using namespace std;

// Step 2: Binary search within the identified row
bool searchInRow(const vector<vector<int>> &matrix, int row, int target)
{
  int colsSize = matrix[0].size();
  int st = 0;
  int end = colsSize - 1; // Fixed: altered from 0 to last index

  while (st <= end)
  {
    int mid2 = st + (end - st) / 2; // Fixed: typo 'en' to 'end'

    if (matrix[row][mid2] == target)
    {
      return true;
    }
    else if (matrix[row][mid2] < target)
    {
      st = mid2 + 1;
    }
    else
    {
      end = mid2 - 1;
    }
  }
  return false;
}

// Step 1: Binary search to find the correct row
bool SearchMatrix(const vector<vector<int>> &matrix, int target)
{
  if (matrix.empty() || matrix[0].empty())
    return false;

  int rowSize = matrix.size();
  int colsSize = matrix[0].size();
  int startRow = 0;
  int endRow = rowSize - 1;

  while (startRow <= endRow)
  {
    int mid = startRow + (endRow - startRow) / 2;

    // Check if the target lies within the boundaries of the current row
    if (target >= matrix[mid][0] && target <= matrix[mid][colsSize - 1])
    {                                          // Fixed: removed stray semicolon
      return searchInRow(matrix, mid, target); // Fixed: passed 'mid' as the row index
    }
    // If target is greater than the largest element of this row, look down
    else if (target > matrix[mid][colsSize - 1])
    { // Fixed: typo 'cols' to 'colsSize'
      startRow = mid + 1;
    }
    // If target is smaller than the smallest element of this row, look up
    else
    {
      endRow = mid - 1;
    }
  }
  return false;
}

int main()
{
  vector<vector<int>> matrix = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 60}};

  int target = 16;

  if (SearchMatrix(matrix, target))
  {
    cout << "Element " << target << " found in the matrix!" << endl;
  }
  else
  {
    cout << "Element " << target << " not found." << endl;
  }

  return 0;
}

// another variatio with col sort and row sort
// #include <iostream>
// #include <vector>
// #include <utility> // Needed for pair

// using namespace std;

// // Saddleback search: Returns {row, col} if found, otherwise {-1, -1}
// pair<int, int> searchItem(const vector<vector<int>>& mat, int target) {
//     int rowSize = mat.size();
//     int colsSize = mat[0].size();

//     int row = 0;
//     int col = colsSize - 1; // Start at top-right corner

//     // FIXED: Changed 'colsSize >= 0' to 'col >= 0' to prevent infinite loop
//     while (row < rowSize && col >= 0) {
//         if (target == mat[row][col]) {
//             return {row, col}; // Found! Return coordinates
//         } else if (target < mat[row][col]) {
//             col--; // Target is smaller, discard this entire column
//         } else {
//             row++; // Target is larger, discard this entire row
//         }
//     }
//     return {-1, -1}; // Not found
// }

// int main() {
//     vector<vector<int>> mat = {
//         {1,  4,  7, 11, 15},
//         {2,  5,  8, 12, 19},
//         {3,  6,  9, 16, 22},
//         {10, 13, 14, 17, 24},
//         {18, 21, 23, 26, 40}
//     };

//     int target = 16;

//     // Call function and store resulting coordinates
//     pair<int, int> result = searchItem(mat, target);

//     // FIXED: Accessing row and col safely from the returned pair
//     if (result.first != -1) {
//         cout << "Target found at index: [" << result.first << "][" << result.second << "]" << endl;
//         cout << "Value at index is: " << mat[result.first][result.second] << endl;
//     } else {
//         cout << "Target not found." << endl;
//     }

//     return 0;
// }

// two sum with hashing logic

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// vector<int> twoSum(int arr[], int n, int target) {
//     unordered_map<int, int> m;
//     vector<int> ans;

//     for (int i = 0; i < n; i++) {
//         int first = arr[i];
//         int sec = target - first;

//         if (m.find(sec) != m.end()) {
//             ans.push_back(i);
//             ans.push_back(m[sec]);
//             break;
//         }
//         // FIX: Insert the current number and its index into the map
//         m[first] = i;
//     }
//     return ans;
// }

// int main() {
//     int n = 4;
//     int arr[4] = {2, 11, 15,7};
//     int target = 9;

//     // FIX: Passed 'arr' correctly and matched parameter order (arr, n, target)
//     vector<int> result = twoSum(arr, n, target);

//     // FIX: Loop to print the vector elements
//     for (int index : result) {
//         cout << index << " ";
//     }

//     return 0;
// }

// finding duplicates
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// void findDuplicates(const vector<int>& arr) {
//     // Step 1: Create an unordered_set to track numbers we have already seen
//     unordered_set<int> seen;

//     // Step 2: Create another set to keep track of duplicates we have already printed
//     unordered_set<int> duplicatesPrinted;

//     cout << "Duplicate elements are: ";
//     bool foundDuplicate = false;

//     // Step 3: Loop through each element in the array
//     for (int num : arr) {

//         // Step 4: Check if the current number is already in the 'seen' set
//         if (seen.find(num) != seen.end()) {

//             // Step 5: If it is seen, check if we haven't printed it yet
//             if (duplicatesPrinted.find(num) == duplicatesPrinted.end()) {
//                 cout << num << " ";
//                 duplicatesPrinted.insert(num); // Mark as printed
//                 foundDuplicate = true;
//             }
//         } else {
//             // Step 6: If it is a new number, add it to the 'seen' set
//             seen.insert(num);
//         }
//     }

//     if (!foundDuplicate) {
//         cout << "None";
//     }
//     cout << endl;
// }

// int main() {
//     // Example array with duplicates (2 and 7 appear multiple times)
//     vector<int> arr = {2, 7, 11, 2, 15, 7, 7};

//     findDuplicates(arr);

//     return 0;
// }

// find duplicates with slow and fast pointer
// #include <iostream>
// #include <vector>
// using namespace std;
// bool isDuplicates(int arr[])
// {

//   int slow = arr[0];
//   int fast = arr[0];

//   do
//   {
//     // slow pointer
//     slow = arr[slow];
//     // fast
//     fast = arr[arr[fast]];
//   } while (slow != fast);
//   {
//     slow = arr[0];
//   }
//   while (slow != fast)
//   {
//     slow = arr[slow];
//     fast = arr[fast];

//   }

// };

// int main()
// {
//   int arr[10] = {1, 3, 4, 5, 9};
//   if (isDuplicates(arr))
//   {
//     cout << "yes it is duplicated";
//   }
//   else
//   {
//     cout << arr << " array is not duplicated";
//   }
//   return 0;
// }

// 3 sum =0; bruteforce
// #include <iostream>
// using namespace std;

// // Changed return type to bool to indicate if a triplet was found
// bool isThreeSum(int arr[], int n) { 
//     for (int i = 0; i < n; i++) { 
//         for (int j = i + 1; j < n; j++) { 
//             for (int k = j + 1; k < n; k++) { 
//                 if (arr[i] + arr[j] + arr[k] == 0) { 
//                     // Print indices and their corresponding values
//                     cout << "Found Triplet:\n";
//                     cout << "Index " << i << " = " << arr[i] << "\n";
//                     cout << "Index " << j << " = " << arr[j] << "\n";
//                     cout << "Index " << k << " = " << arr[k] << "\n";
//                     return true; 
//                 } 
//             } 
//         } 
//     } 
//     return false; 
// } 

// int main() { 
//     int n = 6; 
//     int arr[6] = {1, 0, -1, 2, 2, 6}; 
    
//     if (!isThreeSum(arr, n)) {
//         cout << "No triplet with zero sum found." << endl;
//     }
    
//     return 0; 
// }

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// // Returns a vector of vectors containing all unique triplets that sum to 0
// vector<vector<int>> threeSum(int arr[], int n) {
//     // Set to automatically store unique, sorted triplets
//     set<vector<int>> uniqueTriplets;

//     // Brute force 3-loop search
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 if (arr[i] + arr[j] + arr[k] == 0) {
//                     // Create the triplet
//                     vector<int> triplet = {arr[i], arr[j], arr[k]};
                    
//                     // Sort to ensure uniqueness regardless of original array order
//                     sort(triplet.begin(), triplet.end());
                    
//                     // Insert into set (duplicates are automatically ignored)
//                     uniqueTriplets.insert(triplet);
//                 }
//             }
//         }
//     }

//     // Push all unique values from the set back into a vector
//     vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
//     return result;
// }

// int main() {
//     int n = 6;
//     int arr[6] = {1, 0, -1, 2, 2, 6};

//     vector<vector<int>> triplets = threeSum(arr, n);

//     if (triplets.empty()) {
//         cout << "No triplet with zero sum found." << endl;
//     } else {
//         cout << "Found Unique Triplets:" << endl;
//         for (const auto& triplet : triplets) {
//             cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
//         }
//     }

//     return 0;
// }


// #include<iostream>
// #include <vector>
// #include <set>
// #include <unordered_set>
// #include <algorithm>

// using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     int n = nums.size();
//     set<vector<int>> uniqueTriplets; // Fixed: replaced ':' with ';'

//     for (int i = 0; i < n; i++) {
//         // Hash set to store elements strictly between index i and j
//         unordered_set<int> s; 
        
//         for (int j = i + 1; j < n; j++) {
//             // Formula: nums[i] + nums[j] + third = 0 -> third = -(nums[i] + nums[j])
//             int third = -(nums[i] + nums[j]);

//             // If the third element exists in our hash set, we found a triplet
//             if (s.find(third) != s.end()) {
//                 vector<int> trip = {nums[i], nums[j], third}; // Fixed variable name & brackets
//                 sort(trip.begin(), trip.end());
//                 uniqueTriplets.insert(trip);
//             }
            
//             // Insert current element into hash set for subsequent j-loops
//             s.insert(nums[j]);
//         }
//     }

//     // Move everything from the unique set into the final return vector
//     vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
//     return ans;
// }

// int main() {
//     vector<int> nums = {1, 0, -1, 2, 2, 6};
//     vector<vector<int>> result = threeSum(nums);

//     cout << "Found Unique Triplets:" << endl;
//     for (const auto& triplet : result) {
//         cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
//     }

//     return 0;
// }




// three sum with optimized form mean two pointer  but  remmeber array ill be sorted
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<vector<int>> ans;
//     int n = nums.size();
    
//     // Array must be sorted first
//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < n; i++) {
//         // Skip duplicate elements for i
//         if (i > 0 && nums[i] == nums[i - 1]) continue;

//         int j = i + 1;
//         int k = n - 1;

//         while (j < k) {
//             int sum = nums[i] + nums[j] + nums[k];

//             if (sum > 0) {
//                 k--; // Decrease sum by moving right pointer left
//             } else if (sum < 0) {
//                 j++; // Increase sum by moving left pointer right
//             } else {
//                 ans.push_back({nums[i], nums[j], nums[k]});

//                 // Skip duplicate elements for j and k
//                 while (j < k && nums[j] == nums[j + 1]) j++;
//                 while (j < k && nums[k] == nums[k - 1]) k--;

//                 j++;
//                 k--;
//             }
//         }
//     }
//     return ans;
// }

// int main() {
//     vector<int> nums = {-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> result = threeSum(nums);
    
//     for (const auto& triplet : result) {
//         cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
//     }
//     return 0;
// }


// 4th sum
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // Returns a 2D vector containing all unique quadruplets that sum up to the target
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     vector<vector<int>> ans;
//     int n = nums.size();
    
//     // 4Sum requires at least 4 elements
//     if (n < 4) return ans; 
    
//     // Step 1: Sort the array to use the two-pointer technique
//     sort(nums.begin(), nums.end());
    
//     // First outer loop for the 1st element
//     for (int i = 0; i < n - 3; i++) {
//         // Skip duplicate values for the 1st element
//         if (i > 0 && nums[i] == nums[i - 1]) continue;
        
//         // Second outer loop for the 2nd element
//         for (int j = i + 1; j < n - 2; j++) {
//             // Skip duplicate values for the 2nd element
//             if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
//             // Two pointers for the 3rd and 4th elements
//             int left = j + 1;
//             int right = n - 1;
            
//             while (left < right) {
//                 // Use long long to prevent integer overflow during addition
//                 long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                
//                 if (sum < target) {
//                     left++; // Sum too small, move left pointer right
//                 } else if (sum > target) {
//                     right--; // Sum too big, move right pointer left
//                 } else {
//                     // Found a valid quadruplet
//                     ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
//                     // Skip duplicate values for the 3rd and 4th elements
//                     while (left < right && nums[left] == nums[left + 1]) left++;
//                     while (left < right && nums[right] == nums[right - 1]) right--;
                    
//                     // Move both pointers inward
//                     left++;
//                     right--;
//                 }
//             }
//         }
//     }
//     return ans;
// }

// int main() {
//     vector<int> nums = {1, 0, -1, 0, -2, 2};
//     int target = 0;
    
//     vector<vector<int>> result = fourSum(nums, target);
    
//     // Print the quadruplets
//     cout << "Unique quadruplets that sum to " << target << ":\n";
//     for (const auto& quad : result) {
//         cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]\n";
//     }
    
//     return 0;
// }
