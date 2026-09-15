
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
