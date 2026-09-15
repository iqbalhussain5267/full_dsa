// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   vector<int> vec={1,2,3,4,5,6,7,8,9};
//   cout << vec[0] << endl;
//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   vector<int> vec(5,0);
//   cout<<vec[0]<<endl;
//   cout<<vec[1]<<endl;
//   cout<<vec[2]<<endl;
//   cout<<vec[3]<<endl;

//   return 0;
// }

// for each loop

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   vector<char> vec = {'a', 'b', 'c', 'd'};
//   cout << "size =" << vec.size() << endl;
//   vec.push_back('i');
//   vec.push_back('i');
//   vec.push_back('i');
//   vec.push_back('i');
//   vec.push_back('i');
//   // vec.pop_back();
//   cout << "this is  front value  " << vec.front() << endl;
//   cout << "this is  backvalue value  " << vec.back() << endl;
//   cout << "capacity of vector always become double with respect to  size when space required  " << vec.capacity() << endl;
//   cout << "size =" << vec.size() << endl;
//   for (char i : vec)
//   {
//     cout << i << endl;
//   }
//   return 0;
// }

// question 1
// find unique number in vector {1,2,2,3,3}
// so for this we used xor propert bcs
// n xor n=0
// n xor 0=n
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ans = 0;
    vector<int> nums = {3, 2, 2, 3, 3};

    for (int i : nums)
    {
        ans = ans ^ i; // XOR the current number with ans
    }

    cout << "The unique number is: " << ans << endl;

    return 0;
}
