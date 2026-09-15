// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   // iterator
// vector<int> vec={1,2,3,4,5,6,7,8};
// vector<int>::iterator it;
// for(it=vec.begin();it !=vec.end();it++){
//   cout<<*(it)<<" ";
// }

//   return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};

//     // The compiler automatically picks the correct reverse_iterator type
//     for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
//         cout << *it << " ";
//     }

//     return 0;
// }

// list

// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;
// int main()
// {
//   list<int> l;
//   l.push_back(10222);
//   l.push_front(100);
//   for(int val:l)
//   {
//     cout<<"val "<<val<<" ";
//   }
//   cout<<endl;
//   return 0;
// }

// deque
// #include <iostream>
// #include <vector>
// #include <deque>
// using namespace std;
// int main()
// {
//   deque<int> d;
//   d.push_back(10222);
//   d.push_front(100);
//   for (int val : d)
//   {
//     cout << "val " << val << " ";
//   }
//   cout << "\nvalue at index : 1 = " << d[1];
//   cout << endl;
//   return 0;
// }

// // pair
// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//   // pair<int,string> pair={1,"iqbal"};
//   pair<int ,pair<int,string>> dp={1,{12,"iqball"}};
//   cout<<dp.first<<endl;
//   cout<<dp.second.second;
//   // cout<<dp.second<<endl;

//   return 0;
// }

// vector with pair
// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;
// int main()
// {
//   vector<pair<int, int>> vec = {{1, 2}, {2, 4}, {5, 7}, {6, 9}};
//   vec.push_back({300,500});
//   vec.emplace_back(12,23);
//   for (auto val : vec)
//   {
//     cout << val.first << " " << val.second << endl;
//   }
//   return 0;
// }

// map
// #include <iostream>
// #include <vector>
// #include <list>
// #include <map>
// using namespace std;
// int main()
// {
//   map<string, int> m;
//   m["marks"] = 100;
//   m["mark"] = 100;
//   m["mar"] = 100;
//   m["maks"] = 100;
//   m["mrks"] = 100;
//   m["mars"] = 100;
//   m.insert({"camera", 1200});
//   for (auto p : m)
//   {
//     cout << p.first << "\t " << p.second << endl;
   
//   }
//   if(m.find("camera") !=m.end()){
//     cout<<"found bhai jan \n";
//   } else{
//     cout<<"not founded \n";
//   }
//  cout << "count" << "\t " << m.count("marks") << endl;
//  cout << "value" << "\t " << m["marks"] << endl;
//   return 0;
// }

// multimap
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
int main()
{
  multimap<string, int> m;
  m.emplace("tv",100);
  m.emplace("tv",100);
  m.emplace("tv",100);
  m.emplace("tv",100);
  m.emplace("tv",100);


  // when we used erase so all will be erase but when when we used itarator so operator 
  // on will erase
  // m.erase("tv")
  m.erase(m.find("tv"));
  for (auto p : m)
  {
    cout << p.first << "\t " << p.second << endl;
   
  }

  return 0;
}