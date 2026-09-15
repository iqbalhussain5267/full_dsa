// #include<iostream>
// #include<stack>
// using namespace std;


// int main(){
// stack<int> s;
// s.push(10);
// s.push(20);
// s.push(30);
// s.push(40);
// cout<<"Top element: "<<s.top()<<endl;
// cout<<"Stack size: "<<s.size()<<endl;
//   return 0;
// }



//  question paranthsis validity
// #include<iostream>
// #include<stack>
// using namespace std;


// int main(){
// stack<char> s;
// s.push('(');

//   return 0;
// }



// queue structure

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;

    return 0;
}




