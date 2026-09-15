// #include <iostream>
// #include <vector>

// // We use 'std::vector<char>' to easily add and remove letters
// void makeWords(std::vector<char>& currentWord) {
    
//     // 1. BASE CASE: If the word has 2 letters, print it and stop
//     if (currentWord.size() == 2) {
//         for (char letter : currentWord) {
//             std::cout << letter;
//         }
//         std::cout << "\n";
//         return; 
//     }

//     // 2. CHOOSE 'A'
//     currentWord.push_back('A');  
//     makeWords(currentWord);      // TRY IT (Explore)
//     currentWord.pop_back();      // UNDO (Backtrack)

//     // 3. CHOOSE 'B'
//     currentWord.push_back('B');  
//     makeWords(currentWord);      // TRY IT (Explore)
//     currentWord.pop_back();      // UNDO (Backtrack)
// }

// int main() {
//     std::vector<char> emptyWord;
//     makeWords(emptyWord);
//     return 0;
// }



// combination sum :can include one element mulyple time eg{2,3,5} target=8 ans={2,2,2,2},{2,3,3},{3,5}
// #include <iostream>
// #include <vector>

// using namespace std;

// void getAllCombinations(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& ans, int idx) {
//     // FIX 1: If target is 0, we found a valid combination!
//     if (target == 0) {
//         ans.push_back(combination);
//         return;
//     }

//     // FIX 2: Stop if we look past the array OR if target becomes negative (Pruning)
//     if (idx == candidates.size() || target < 0) {
//         return;
//     }

//     // CHOICE 1: Pick the current element candidates[idx]
//     combination.push_back(candidates[idx]);
    
//     // EXPLORE option A: We pick it and we CAN pick it again (idx stays same)
//     getAllCombinations(candidates, target - candidates[idx], combination, ans, idx);
    
//     // UNDO: Backtrack (remove the choice)
//     combination.pop_back();

//     // CHOICE 2: Skip the current element entirely
//     // EXPLORE option B: Move to the next index (idx + 1)
//     getAllCombinations(candidates, target, combination, ans, idx + 1);
// }

// vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//     vector<vector<int>> ans; // FIX 3: Corrected data type to store lists of numbers
//     vector<int> combination;
//     getAllCombinations(candidates, target, combination, ans, 0);
//     return ans;
// }

// int main() {
//     vector<int> arr = {2, 3, 5};
//     int target = 8;

//     vector<vector<int>> result = combinationSum(arr, target);

//     // Print the results to see if it works
//     cout << "Combinations that sum up to " << target << ":\n";
//     for (const auto& comb : result) {
//         cout << "[ ";
//         for (int num : comb) {
//             cout << num << " ";
//         }
//         cout << "]\n";
//     }

//     return 0;
// }




// merge sort
// #include<iostream>
// #include<vector>
// using namespace std;

// void merge(vector<int> &arr ,int start,int mid,int end){
//     vector<int> temp;
//     int i=start;
//     int j=mid+1;
    
//     while(i<=mid && j<=end){
//         if(arr[i]<arr[j]){
//             temp.push_back(arr[i]);
//             i++;
//         }
//         else{
//             temp.push_back(arr[j]);
//             j++;
//         }
//     }
    
//     while(i<=mid){
//         temp.push_back(arr[i]);
//         i++;
//     }
    
//     while(j<=end){
//         temp.push_back(arr[j]);
//         j++;
//     }
    
//     for(int k=0;k<temp.size();k++){
//         arr[start+k]=temp[k];
//     }
// }

// void mergeSort(vector<int> &arr,int start,int end){
//     if(start<end){
//         int mid=start + (end-start)/2;
//         // left part of array
//         mergeSort(arr,start,mid);
//         // right part
//         mergeSort(arr,mid+1,end);
//         merge(arr,start,mid,end);
//     }
// }

// int main(){
//     vector<int> arr={12,31,35,8,32,17};
//     int start=0;
//     int end=arr.size()-1;
    
//     // Sort the vector
//     mergeSort(arr,start,end);
    
//     // ADDED: Print the sorted vector
//     cout << "Sorted array: ";
//     for(int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     return 0;
// }



// quick sort
// #include <iostream>
// #include <vector>
// using namespace std;


// int partition(vector<int> &arr, int start, int end) {
//     int pivot = arr[end];
//     int i = start - 1;

//     for (int j = start; j < end; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[end]);
//     return i + 1;
// }
// void quickSort(vector<int> &arr, int start, int end) {
//     if (start >= end) {
//         return;
//     }
//     int pivoteIndex=partition(arr,start,end);
//     // left partr
//     quickSort(arr,start,pivoteIndex-1);
//     // right part
//     quickSort(arr,pivoteIndex+1,end);
// }

// int main() {
//     vector<int> arr = {10, 80, 30, 90, 40};
//     int start = 0;
//     int end = arr.size() - 1;

//     quickSort(arr, start, end);

//     cout << "Sorted array: ";
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }



// count inversion: i > j but arr[i] >arr[j]



// merge sort
// #include<iostream>
// #include<vector>
// using namespace std;

// int merge(vector<int> &arr ,int start,int mid,int end){
//     vector<int> temp;
//     int i=start;
//     int j=mid+1;
//     int count=0;
    
//     while(i<=mid && j<=end){
//         if(arr[i]<arr[j]){
//             temp.push_back(arr[i]);
//             i++;
//         }
//         else{
//             temp.push_back(arr[j]);
//             j++;
//             count=(mid-i+1);
//         }
//     }
    
//     while(i<=mid){
//         temp.push_back(arr[i]);
//         i++;
//     }
    
//     while(j<=end){
//         temp.push_back(arr[j]);
//         j++;
//     }
    
//     for(int k=0;k<temp.size();k++){
//         arr[start+k]=temp[k];
//     }
//     return count;
// }

// int  mergeSort(vector<int> &arr,int start,int end){
//     if(start<end){
//         int mid=start + (end-start)/2;
//         // left part of array
//         int leftInvCount=mergeSort(arr,start,mid);
//         // right part
//       int   rightInvCount=mergeSort(arr,mid+1,end);
//      int currInvCount=   merge(arr,start,mid,end);
//      return leftInvCount+rightInvCount+currInvCount;
//     }
//     return 0;
// };
// int main(){
//     vector<int> arr={6,3,5,2,7};
//     int start=0;
//     int end=arr.size()-1;
//     int ans=mergeSort(arr,start,end);
//     cout<<"inversion count is :"<<ans<<endl;
//     return 0;
// }



// k night tour
