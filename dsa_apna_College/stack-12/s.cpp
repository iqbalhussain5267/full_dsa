// #include <iostream>
// #include <vector>
// using namespace std;
// class Stack
// {
//   vector<int> v;

// public:
//   void push(int val)
//   {
//     return v.push_back(val);
//   }
//   void pop()
//   {
//     return v.pop_back();
//   }
//   int top()
//   {
//     return v[v.size() - 1];
//   }
//   bool empty()
//   {
//     return v.size() == 0;
//   }
// };
// int main()
// {

//   Stack s;
//   s.push(12);
//   s.push(1);
//   s.push(2);
//   while(!s.empty()){
// cout<<s.top()<<" ";
// s.pop();
//   }
//   return 0;
// }

// using linkedlist approach

// #include<iostream>
// #include<list>

// using namespace std;
// class Stack{
//   list<int> l;
//   public:
// void push_front(int val){
// return   l.push_front(val);
// }
// void pop_front(){
//   return  l.pop_front();
// }
// int top(){
//   return l.front();
// }
// bool empty(){
// return l.size()==0;
// }
// };

// int main(){

// Stack s;
// s.push_front(9);
// s.push_front(0);
// s.push_front(7);
// s.push_front(1);
// while (!s.empty()){
//   cout<<s.top()<<" ";
//   s.pop_front();

// }
//   return 0;
// }

// EASIEST WAY
// #include <iostream>
// #include <stack>

// using namespace std;
// int main()
// {
//   stack<int> s;
//   s.push(12334);
//   s.push(234);
//   s.push(1234);
//   s.push(134);
//   while (!s.empty())
//   {
//     cout << s.top() << " `";
//     s.pop();
//   }

//   return 0;
// }
// VALID PARENTHESIS
// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// class solution
// {
// public:
//   bool validParenthesis(string str)
//   {
//     stack<char> st;

//     for (int i = 0; i < str.size(); i++)
//     {
//       // 1. If it's an opening bracket, push it to the stack
//       if (str[i] == '(' || str[i] == '{' || str[i] == '[')
//       {
//         st.push(str[i]);
//       }
//       // 2. If it's a closing bracket, check for a valid match
//       else
//       {
//         // If stack is empty but we see a closing bracket, it's invalid
//         if (st.empty())
//           return false;

//         char topChar = st.top();
//         if ((str[i] == ')' && topChar == '(') ||
//             (str[i] == '}' && topChar == '{') ||
//             (str[i] == ']' && topChar == '['))
//         {
//           st.pop(); // Valid match found, pop it
//         }
//         else
//         {
//           return false; // Mismatched brackets
//         }
//       }
//     }

//     // 3. If stack is empty, all brackets were matched properly
//     return st.empty();
//   }
// };

// int main()
// {
//   solution s;
//   string str = "({[]})";

//   if (s.validParenthesis(str))
//   {
//     cout << "The string \"" << str << "\" is valid." << endl;
//   }
//   else
//   {
//     cout << "The string \"" << str << "\" is invalid." << endl;
//   }

//   return 0;
// }

// next greatest

// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// // Function to find the next greater element for each position
// vector<int> nextGreaterElement(const vector<int>& arr) {
//     int n = arr.size();
//     vector<int> nge(n, -1); // Initialize result vector with -1
//     stack<int> s;

//     // Traverse the array from right to left
//     for (int i = n - 1; i >= 0; i--) {
//         // Pop elements from stack that are smaller than or equal to current element
//         while (!s.empty() && s.top() <= arr[i]) {
//             s.pop();
//         }

//         // If stack is not empty, the top element is the next greater element
//         if (!s.empty()) {
//             nge[i] = s.top();
//         }

//         // Push the current element onto the stack for upcoming elements
//         s.push(arr[i]);
//     }
//     return nge;
// }

// int main() {
//     // Example input vector
//     vector<int> v = {4, 5, 2, 25};

//     // Find next greater elements
//     vector<int> result = nextGreaterElement(v);

//     // Print the results
//     cout << "Element -> Next Greater Element" << endl;
//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] << " -> " << result[i] << endl;
//     }

//     return 0;
// }

// previous small
// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// // Function to find the previous smaller element for each position
// vector<int> previousSmallerElement(const vector<int>& arr) {
//     int n = arr.size();
//     vector<int> pse(n, -1); // Initialize result vector with -1
//     stack<int> s;

//     // Traverse the array from left to right
//     for (int i = 0; i < n; i++) {
//         // Pop elements from stack that are greater than or equal to current element
//         while (!s.empty() && s.top() >= arr[i]) {
//             s.pop();
//         }

//         // If stack is not empty, the top element is the previous smaller element
//         if (!s.empty()) {
//             pse[i] = s.top();
//         }

//         // Push the current element onto the stack for upcoming elements
//         s.push(arr[i]);
//     }
//     return pse;
// }

// int main() {
//     // Example input vector
//     vector<int> v = {4, 10, 5, 8, 20, 15, 3, 12};

//     // Find previous smaller elements
//     vector<int> result = previousSmallerElement(v);

//     // Print the results
//     cout << "Element -> Previous Smaller Element" << endl;
//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] << " -> " << result[i] << endl;
//     }

//     return 0;
// }

// next greatest accordin g to second array
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <unordered_map>

// using namespace std;

// // Function to find next greater elements for nums1 based on nums2
// vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
// {
//   unordered_map<int, int> next_greater;
//   stack<int> s;

//   // Process nums2 from right to left to precompute next greater elements
//   for (int i = nums2.size() - 1; i >= 0; i--)
//   {
//     int current = nums2[i];

//     // Maintain a monotonic decreasing stack
//     while (!s.empty() && s.top() <= current)
//     {
//       s.pop();
//     }

//     // If stack is not empty, top element is the next greater
//     if (!s.empty())
//     {
//       next_greater[current] = s.top();
//     }
//     else
//     {
//       next_greater[current] = -1; // No greater element exists
//     }

//     // Push current element for future lookups
//     s.push(current);
//   }

//   // Build the result array for nums1 using the map
//   vector<int> result;
//   for (int num : nums1)
//   {
//     result.push_back(next_greater[num]);
//   }

//   return result;
// }

// int main()
// {
//   // Example test case
//   vector<int> nums1 = {4, 1, 2};
//   vector<int> nums2 = {1, 3, 4, 2};

//   vector<int> result = nextGreaterElement(nums1, nums2);

//   // Print output
//   cout << "Nums1 element -> Next Greater in Nums2:" << endl;
//   for (int i = 0; i < nums1.size(); i++)
//   {
//     cout << nums1[i] << " -> " << result[i] << endl;
//   }

//   return 0;
// }


// largest histogram rectangle
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left_min(n);
    vector<int> right_min(n);
    stack<int> s; // Stack will store indices, not values

    // Step 1: Find Left Min (Previous Smaller Element Index) for each bar
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        // If stack is empty, no smaller element on left; boundary is -1
        left_min[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack to reuse it for Right Min
    while (!s.empty()) s.pop();

    // Step 2: Find Right Min (Next Smaller Element Index) for each bar
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        // If stack is empty, no smaller element on right; boundary is n
        right_min[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Step 3: Calculate maximum area using the left and right boundaries
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        int width = right_min[i] - left_min[i] - 1;
        int area = heights[i] * width;
        max_area = max(max_area, area);
    }

    return max_area;
}

int main() {
    // Example histogram heights: [2, 1, 5, 6, 2, 3]
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    cout << "Max Rectangle Area: " << largestRectangleArea(heights) << endl;
    
    return 0;
}
