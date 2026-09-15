// #include <iostream>
// #include <vector>
// using namespace std;

// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         // FIX: Changed '=' to '<' to correctly bound the inner loop
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n = 5;
//     int arr[] = {4, 1, 5, 2, 3};
//     bubbleSort(arr, n);
//     printArray(arr, n); // Outputs: 1 2 3 4 5
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void selectionSort(int arr[], int n) {
//     // Loop through each element except the last one
//     for (int i = 0; i < n - 1; i++) {
//         int min_idx = i; // Assume the current element is the minimum

//         // Find the actual minimum element in the remaining unsorted array
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[min_idx]) {
//                 min_idx = j; // Update index of the minimum element
//             }
//         }

//         // Swap the found minimum element with the first unsorted element
//         if (min_idx != i) {
//             swap(arr[i], arr[min_idx]);
//         }
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n = 5;
//     int arr[] = {4, 1, 5, 2, 3};

//     selectionSort(arr, n);
//     printArray(arr, n); // Outputs: 1 2 3 4 5

//     return 0;
// }

// question  sort array of 0s,1s,and 2s brute force
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n = 6;
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;
//     int arr[6] = {2, 2, 1, 0, 1, 0};

//     // Step 1: Count occurrences of 0, 1, and 2
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == 0) {
//             count0++;
//         } else if (arr[i] == 1) {
//             count1++;
//         } else {
//             count2++;
//         }
//     }

//     // Step 2: Overwrite the array using index++
//     int index = 0;
//     for (int i = 0; i < count0; i++) {
//         arr[index++] = 0;
//     }
//     for (int i = 0; i < count1; i++) {
//         arr[index++] = 1;
//     }
//     for (int i = 0; i < count2; i++) {
//         arr[index++] = 2;
//     }

//     // Step 3: Print the sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }



// merge 2 sort array :A=[1,2,3,0,0,0] size=m B={2,5,6} size=n total size=m+n
// #include <iostream>
// using namespace std;

// int main() {
//     int m = 3; // Number of valid elements in A
//     int n = 3; // Number of elements in B
    
//     int i = m - 1;     // Pointer for the last valid element in A (index 2)
//     int j = n - 1;     // Pointer for the last element in B (index 2)
//     int index = m + n - 1; // Pointer for the last slot of the merged array (index 5)

//     int A[] = {1, 2, 3, 0, 0, 0};
//     int B[] = {2, 5, 6};

//     // Merge from right to left
//     while (i >= 0 && j >= 0) {
//         if (A[i] >= B[j]) {
//             A[index] = A[i];
//             i--;
//         } else {
//             A[index] = B[j];
//             j--;
//         }
//         index--;
//     }

//     // If there are remaining elements in B, copy them over
//     // (Elements remaining in A are already in their correct places)
//     while (j >= 0) {
//         A[index] = B[j];
//         j--;
//         index--;
//     }

//     // Print the merged array
//     for (int k = 0; k < m + n; k++) {
//         cout << A[k] << " ";
//     }
    
//     return 0;
// }


// next permuatation
#include <iostream>
#include <vector>

using namespace std;

// Helper function to reverse a portion of the vector using a for loop
void reverseSection(vector<int>& nums, int start, int end) {
    int totalElements = (end - start + 1) / 2;
    for (int k = 0; k < totalElements; k++) {
        swap(nums[start + k], nums[end - k]);
    }
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;

    // Step 1: Find the first decreasing element from the right
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break; // Found the pivot, exit loop
        }
    }

    // Step 2: If pivot exists, find the next larger element and swap
    if (pivot != -1) {
        for (int j = n - 1; j > pivot; j--) {
            if (nums[j] > nums[pivot]) {
                swap(nums[pivot], nums[j]);
                break; // Swapped, exit loop
            }
        }
    }

    // Step 3: Reverse the elements after the pivot
    reverseSection(nums, pivot + 1, n - 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    nextPermutation(nums);

    // Print result
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
