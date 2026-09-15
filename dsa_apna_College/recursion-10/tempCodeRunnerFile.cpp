
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     // Helper function to generate permutations recursively
//     void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
//         // Base Case: If index reaches the end, a full permutation is formed
//         if (idx == nums.size()) {
//             ans.push_back(nums);
//             return;
//         }

//         // Loop to explore all choices for the current position 'idx'
//         for (int i = idx; i < nums.size(); i++) {
//             swap(nums[idx], nums[i]); // Choose: Put ith element at idx position
//             getPerms(nums, idx + 1, ans); // Explore: Recurse for the next index
//             swap(nums[idx], nums[i]); // Unchoose: Backtrack to restore original state
//         }
//     }

//     // Main function called by the user
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         getPerms(nums, 0, ans); // Start recursion from index 0
//         return ans;
//     }
// };

// int main() {
//     Solution solver;
//     vector<int> nums = {1, 2, 3}; // Sample input

//     vector<vector<int>> result = solver.permute(nums);

//     // Print the permutations
//     cout << "[" << endl;
//     for (const auto& perm : result) {
//         cout << "  [";
//         for (size_t i = 0; i < perm.size(); ++i) {
//             cout << perm[i];
//             if (i < perm.size() - 1) cout << ", ";
//         }
//         cout << "]" << endl;
//     }
//     cout << "]" << endl;

//     return 0;
// }
