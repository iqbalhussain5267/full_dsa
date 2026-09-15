// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   char str[100];
//   cout<<"enter your charachter";
//   cin.getline(str,100);
//   cout<<str;
//   return 0;
// }

// with delimimter
// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   char str[10];
//   cout<<"enter your charachter     ";
// // foreach loop
//   // cin.getline(str,100,'$');
//   cin.getline(str,10);
//   for(char ch:str){
//     cout<<ch<<" ";
//   }
//   cout<<endl;
//   cout<<str;
//   return 0;
// }

// we used null \0 charchter in evry charch array

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   char str[10] = {'s', 'b', 'c', 'g'};
//   int len = 0;
//   for (int i = 0; i < str[i] != '\0'; i++)
//   {
//     len++;
//   }
//   cout << len;
//   return 0;
// }

// STRING: we dont need to declared size first it can be change at run time ,it is dynamic in nature;

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// int main()
// {
//   string str = "iqbal";
//   string str1 = "hussain";
//   string fullname=str+str1;
//   cout<<fullname.length()<<endl;

//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   string str = "data science ";
//   for (int i = 0; i < str.length(); i++)
//   {
//     cout << str[i]<<" ";
//   }
//   // string str;
//   // getline(cin,str);
//   cout << " output is : " << str;
//   return 0;
// }

// reverse string wit chachter array
// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   int n = 4;
//   int start = 0;
//   int end = n - 1;
//   char str[4] = {'a', 'b', 'c', 'd'};
//   while (start < end)
//   {
//     swap(str[start++], str[end--]);
//     // instead of start++ we can write in swap
//     // start++;
//     // end--;
//   }
//   cout << str;
//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {

//   string str = "12332";
//   int start = 0;
//   int n = str.length();
//   int end=n-1;
//   while(start<end){
//     if(str[start]==str[end]){
//       cout<<"yes";
//       start++;
//       end--;

//     }else{
//       cout<<"not";
//       break;
//     }
//   }
//   return 0;
// }

// // remove all occurance
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     string s = "daaabcbdcabshdfgabc";
//     string part = "abc";

//     // Loop runs as long as "abc" is found in the string
//     while (s.length() > 0 && s.find(part) != string::npos) {
//         s.erase(s.find(part), part.length());
//     }

//     // Print the final remaining string
//     cout << "Remaining string: " << s << endl;

//     return 0;
// }

// permuatation in string

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// // Function to check if a permutation of s1 exists inside s2
// bool checkPermutation(string s1, string s2) {
//     int n1 = s1.length();
//     int n2 = s2.length();

//     // If s1 is longer than s2, its permutation cannot fit inside s2
//     if (n1 > n2) {
//         return false;
//     }

//     // Frequency arrays to count occurrences of characters (a-z)
//     vector<int> s1_count(26, 0);
//     vector<int> s2_count(26, 0);

//     // Count character frequencies for s1 and the very first window of s2
//     for (int i = 0; i < n1; i++) {
//         s1_count[s1[i] - 'a']++;
//         s2_count[s2[i] - 'a']++;
//     }

//     // If the first window matches s1's frequency exactly, we found a permutation
//     if (s1_count == s2_count) {
//         return true;
//     }

//     // Slide the window across the rest of s2
//     for (int i = n1; i < n2; i++) {
//         s2_count[s2[i] - 'a']++;        // Include the new character entering the window
//         s2_count[s2[i - n1] - 'a']--;   // Exclude the old character leaving the window

//         // Check if the current window matches s1's frequency
//         if (s1_count == s2_count) {
//             return true;
//         }
//     }

//     // Return false if the window slides to the end without finding a match
//     return false;
// }

// int main() {
//     string s1 = "ab";
//     string s2 = "eidbaooo";

//     // Call the boolean function and print the result
//     if (checkPermutation(s1, s2)) {
//         cout << "Yes, a permutation exists!" << endl;
//     } else {
//         cout << "No permutation found." << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm> // Required for reverse()

// using namespace std;

// int main() {
//     string ans = "";
//     string str = "hello world";
//     int n = str.length();

//     // Step 1: Reverse the entire string -> "dlrow olleh"
//     reverse(str.begin(), str.end());

//     for (int i = 0; i < n; i++) {
//         string word = "";

//         // Step 2: Extract a single word
//         while (i < n && str[i] != ' ') {
//             word += str[i];
//             i++;
//         }

//         // Step 3: Reverse the individual word back to its normal order
//         reverse(word.begin(), word.end());

//         // Step 4: Build the final answer string
//         if (word.length() > 0) {
//             if (ans.length() > 0) {
//                 ans += " "; // Add space between words
//             }
//             ans += word;
//         }
//     }

//     cout << "Original: hello world" << endl;
//     cout << "Reversed: " << ans << endl; // Outputs: "world hello"

//     return 0;
// }

// compress sting

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int compress(vector<char> &chars)
{
  int n = chars.size();
  int writeIndex = 0; // Tracks where to write the compressed characters
  int i = 0;          // Tracks the current character group

  while (i < n)
  {
    char currentChar = chars[i];
    int count = 0;

    // Count occurrences of the current consecutive character
    while (i < n && chars[i] == currentChar)
    {
      count++;
      i++;
    }

    // Write the character itself
    chars[writeIndex++] = currentChar;

    // If count is greater than 1, write the digits of the count
    if (count > 1)
    {
      string countStr = to_string(count);
      for (char c : countStr)
      {
        chars[writeIndex++] = c;
      }
    }
  }

  // Return the new length of the compressed array
  return writeIndex;
}

int main()
{
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'c'};

  int newLength = compress(chars);

  // Print the compressed array up to the new length
  cout << "Compressed length: " << newLength << endl;
  cout << "Compressed array: ";
  for (int i = 0; i < newLength; i++)
  {
    cout << chars[i] << " ";
  }
  cout << endl;

  return 0;
}
