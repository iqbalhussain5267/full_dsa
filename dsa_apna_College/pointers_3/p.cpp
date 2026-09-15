// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   int a = 12;
//   int *ptr = &a;

//   // pointer to pointer
//   int **ptr2 = &ptr;

//   cout << &a << endl;

//   cout << "this is our pointer   :" << ptr << endl;

//   cout << &ptr << " " <<endl;
//   cout << "this is our pointer to pointer  :" << ptr2 << endl;
//   cout << "value at adddress:" << &a<<" IS = "<<* (&a)<< endl;

//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int function(int a)
// {
//   a = 20;
//   return a;
// }
// int main()
// {
//   int a = 10;

//   // PASS BY VALUE
//   function(a);
//   cout << " value pass is " << a;
//   return 0;
// }

// pass by refrence

#include <iostream>
#include <vector>
using namespace std;
void change(int &b) // pass by reference using alias mean refer t a
{
  b = 1200;
  
}
int main()
{
  int a = 12;
  change(a);
  cout << a;
  return 0;
}