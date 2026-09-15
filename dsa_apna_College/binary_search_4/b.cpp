// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n = 5;
//     int target = 4;
//     int r = 0;
//     int l = n - 1;
//     int arr[5] = {1, 2, 3, 4, 5};
//     int index = -1; // Default if not found

//     while (r <= l) {
//         int mid = (r + l) / 2;

//         if (target > arr[mid]) {
//             r = mid + 1;
//         } else if (target < arr[mid]) {
//             l = mid - 1;
//         } else {
//             index = mid; // Store the index position
//             break;       // Exit loop once found
//         }
//     }

//     cout << index;
//     return 0;
// }

// peak index in mountain array
// #include<iostream>
// using namespace std;

// int main(){
//     int n = 6;
//     int end = n - 2;
//     int start = 1;
//     int result = -1;
//     int arr[6] = {1, 3, 8, 9, 5, 2};

//     while(start <= end){
//         int mid = (start + end) / 2;

//         // Case 1: Peak element found
//         if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
//             result = mid;
//             break; // FIX 1: Break out of the loop to prevent infinite loop
//         }
//         // Case 2: On the ascending slope, peak lies to the right
//         else if(arr[mid-1] < arr[mid]){
//             start = mid + 1;
//         }
//         // Case 3: On the descending slope, peak lies to the left
//         else{
//             end = mid - 1; // FIX 2: Correctly update 'end' instead of 'start'
//         }
//     }

//     cout << result; // Outputs: 3
//     return 0;
// }

// single element ij sorted array

#include <iostream>  // <-- Add this line
#include <vector> 
using namespace std; 

int main() { 
    int n = 9; 
    int arr[9] = {1, 1, 2, 3, 3, 4, 4, 8, 8}; 
    int start = 0; 
    int end = n - 1; 
    int result = -1; 

    while (start <= end) { 
        int mid = start + (end - start) / 2; 

        if ((mid == 0 || arr[mid] != arr[mid - 1]) && 
            (mid == n - 1 || arr[mid] != arr[mid + 1])) { 
            result = arr[mid]; 
            break; 
        } 

        bool isEvenPair = (mid % 2 == 0); 
        
        if ((isEvenPair && arr[mid] == arr[mid + 1]) || 
            (!isEvenPair && arr[mid] == arr[mid - 1])) { 
            start = mid + 1; 
        } else { 
            end = mid - 1; 
        } 
    } 

    cout << "Single element is: " << result; 
    return 0; 
}
