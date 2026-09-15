// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int val) {
//         data = val;
//         next = NULL; // Fix: Initialize next to NULL
//     }
// };

// class List {
//     Node* head;
//     Node* tail;

// public:
//     List() {
//         head = tail = NULL;
//     }

//     void push_front(int val) {
//         Node* newNode = new Node(val);

//         if (head == NULL) { // Fix: Kept inside the push_front function
//             // insert first node
//             head = tail = newNode;
//             return;
//         } else {
//             // insert subsequent nodes
//             newNode->next = head;
//             head = newNode;
//         }
//     } // Fix: Moved function closing brace here

//     void printall() {
//         Node* temp = head; // Fix: Must be a pointer (Node*)
//         while (temp != NULL) {
//             cout << temp->data << " -> "; // Fix: Fixed 'temm' typos
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main() {
//     List l;
//     l.push_front(2);
//     l.push_front(12);
//     l.push_front(1);

//     l.printall();
//     return 0;
// }

// pushback
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int val) {
//         data = val;
//         next = NULL; // Fix: Initialize next to NULL
//     }
// };

// class List {
//     Node* head;
//     Node* tail;

// public:
//     List() {
//         head = tail = NULL;
//     }

//     void push_back(int val) {
//         Node* newNode = new Node(val);

//         if (head== NULL) { // Fix: Kept inside the push_front function
//             // insert first node
//             head = tail = newNode;
//             return;
//         } else {
//             // insert subsequent nodes
//             tail->next = newNode;
//             tail = newNode;
//         }
//     } // Fix: Moved function closing brace here

//     void printall() {
//         Node* temp = head; // Fix: Must be a pointer (Node*)
//         while (temp != NULL) {
//             cout << temp->data << " -> "; // Fix: Fixed 'temm' typos
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main() {
//     List l;
//     l.push_back(12);
//     l.push_back(1);
//     l.push_back(2);

//     l.printall();
//     return 0;
// }

// popfront
// // #include <iostream>
// // using namespace std;

// // class Node {
// // public:
// //     int data;
// //     Node* next;

// //     Node(int val) {
// //         data = val;
// //         next = NULL;
// //     }
// // };

// // class List {
// //     Node* head;
// //     Node* tail;

// // public:
// //     List() {
// //         head = tail = NULL;
// //     }

// //     void push_front(int val) {
// //         Node* newNode = new Node(val);
// //         if (head == NULL) {
// //             head = tail = newNode;
// //             return;
// //         } else {
// //             newNode->next = head;
// //             head = newNode;
//         }
//     }

//     void pop_front() { // Fix: Removed unused 'int val' parameter
//         if (head == NULL) {
//             cout << "List is empty!" << endl;
//             return;
//         }

//         Node* temp = head;
//         head = head->next;

//         // Fix: If the list is now empty, update tail to NULL
//         if (head == NULL) {
//             tail = NULL;
//         }

//         temp->next = NULL;
//         delete temp;
//     } // Fix: Removed the extra structural closing brace from here

//     void printall() {
//         Node* temp = head;
//         while (temp != NULL) {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// }; // Fix: Class properly ends here now

// int main() {
//     List l;

//     // Add elements
//     l.push_front(2);
//     l.push_front(12);
//     l.push_front(1);
//     cout << "Original list: ";
//     l.printall();

//     // Remove the front element (removes 1)
//     l.pop_front();
//     cout << "After pop_front: ";
//     l.printall();

//     return 0;
// }

// popback
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* Next;
//     Node(int val) {
//         data = val;
//         Next = NULL;
//     }
// };

// class List {
//     Node* head;
//     Node* tail;
// public:
//     List() {
//         head = tail = NULL;
//     }

//     void push_front(int val) {
//         Node* newNode = new Node(val);
//         if (head == NULL) {
//             head = tail = newNode;
//             return;
//         } else {
//             newNode->Next = head;
//             head = newNode;
//         }
//     }

//     void pop_back() {
//         // Case 1: Empty list
//         if (head == NULL) {
//             cout << "List is empty" << endl;
//             return;
//         }

//         // Case 2: Only one element in the list
//         if (head == tail) {
//             delete head;
//             head = tail = NULL;
//             return;
//         }

//         // Case 3: Multiple elements
//         Node* tempo = head;
//         // Traverse to find the second-to-last node
//         while (tempo->Next != tail) {
//             tempo = tempo->Next;
//         }

//         delete tail;       // Free memory of the last node
//         tail = tempo;      // Update tail to second-to-last node
//         tail->Next = NULL; // Break connection to deleted node
//     }

//     // Changed return type from int to void
//     void print() {
//         Node* temp = head;
//         while (temp != NULL) {
//             cout << temp->data << " ";
//             temp = temp->Next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     List l;
//     l.push_front(1);
//     l.push_front(2);
//     l.push_front(4);

//     cout << "Original List: ";
//     l.print(); // Expected Output: 4 2 1

//     l.pop_back();

//     cout << "After pop_back: ";
//     l.print(); // Expected Output: 4 2

//     return 0;
// }

#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};
class List
{
  Node *head;
  Node *tail;

public:
  List()
  {
    head = tail = NULL;
  }
  void push_back(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
      return;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }
  void push_front(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
      return;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }
  void insertMiddle(int val,int pos){
    if(pos<0){
      cout<<" Invalid position"<<endl;
      return;
      
    }if(pos==0){
      push_front(val);
      return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for(int i=0;i<pos-1;i++){
      temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
  }
  void search(int val){
    int pos=0;
    Node* temp=head;
    while(temp!=NULL){
      if(temp->data==val){
        cout<<"Value found at position: "<<pos<<endl;
        return;
      }
      temp=temp->next;
      pos++;
    }
    cout<<"Value not found in the list"<<endl;
  }
  void printall()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main()
{
  List l;
  l.push_back(12);
  l.push_back(1);
  l.push_back(2);
  l.push_front(2122);
  l.insertMiddle(100,2);
  l.printall();
  l.search(100);
  return 0;
}