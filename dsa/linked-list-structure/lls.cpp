#include <iostream>
using namespace std;

// Minimal Node structure with a single constructor
struct Node {
    int data;
    Node* next;

    // The single constructor
    Node(int val) {
        data = val;
        next = nullptr; 
    }
};

int main() {
    // 1. Create independent nodes manually using the constructor
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // 2. Link the nodes together sequentially
    first->next = second;
    second->next = third;

    // 3. Print the list elements sequentially
    Node* temp = first;     
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}




// #include<iostream>
// using namespace std;
// struct Node
// {
//   int data;
//   Node* next;
//   Node(int val) {
//         data = val;
//         next = nullptr; 
//     }
//   /* data */
// };

// int main()
// {
// Node* a=new Node(3000);
// Node* b=new Node(4000);
// Node* c=new Node(5000);
// a->next=b;
// b->next=c;
// Node* temp=a;
// while(temp!=nullptr){
//   cout<<temp->data<<"->";
// // cout<<temp->next<<endl;
//   temp=temp->next;

// }


// cout << "NULL" << endl;

//   return 0;
// }

// // #include <iostream>
// // using namespace std;

// // The structural building block of our linked list
// struct Node {
//     int data;
//     Node* next;

//     // Constructor to initialize a node with a value
//     Node(int val) { 
//         data = val; 
//         next = nullptr; // 'nullptr' or 'NULL' is required in C++ instead of 'null'
//     } 
// };

// // Function to add a new node at the end of the list
// void append(Node*& head, int val) {
//     Node* newNode = new Node(val);
    
//     // If the list is empty, the new node becomes the head
//     if (head == nullptr) {
//         head = newNode;
//         return;
//     }
    
//     // Otherwise, traverse to the last node
//     Node* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
    
//     // Link the last node to our new node
//     temp->next = newNode;
// }

// // Function to print the linked list items sequentially
// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " -> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }

// int main() {
//     // Start with an empty linked list
//     Node* head = nullptr;

//     // Append items to our list
//     append(head, 10);
//     append(head, 20);
//     append(head, 30);

//     // Display the structured elements
//     cout << "Linked List: ";
//     printList(head);

//     return 0;
// }


// operation on linkedlist
// // insertion
// #include <iostream>
// using namespace std;

// struct
//   Node
//   {
//     int data;
//     Node* next;
//     Node(int val) {
//           data = val;
//           next = nullptr; 
//       }
//     /* data */
//   };

//   int main(){
// Node*a=new Node(10);
// Node*b=new Node(20);
// Node*c=new Node(30);
// Node*d=new Node(40);
// a->next=b;
// b->next=c;
// c->next=d;
// //  here is insertion
// Node* temp=a->next;
// Node* newNode = new Node(25); // Create a new node with value 25
// newNode->next = temp; // Link the new node to the next node
// a->next = newNode; // Link the previous node to the new node
//  temp = a; // Start from the head of the listkx

// while(temp!=nullptr){
//   cout<<temp->data<<"->";
//   temp=temp->next;
// }
// cout << "NULL" << endl;

//     return 0;
//   }



// deletion
// #include <iostream>
// using namespace std;

// struct
//   Node
//   {
//     int data;
//     Node* next;
//     Node(int val) {
//           data = val;
//           next = nullptr; 
//       }
//     /* data */
//   };

//   int main(){
// Node*a=new Node(10);
// Node*b=new Node(20);
// Node*c=new Node(30);
// Node*d=new Node(40);
// a->next=b;
// b->next=c;
// c->next=d;
// //  here is deletion
// Node* temp=a->next;
// Node* newNode = new Node(25); // Create a new node with value 25
// newNode->next = temp; // Link the new node to the next node
// a->next = newNode; // Link the previous node to the new node
//  temp = a; // Start from the head of the listkx
// temp->next=temp->next->next->next; // Skip the node with value 20
// while(temp!=nullptr){
//   cout<<temp->data<<"->";
//   temp=temp->next;
// }
// cout << "NULL" << endl;

//     return 0;
//   }