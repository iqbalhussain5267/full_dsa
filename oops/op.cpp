// #include <iostream>
// using namespace std;

// int main()
// {

//     cout << "enter number: ";

//     return 0;
// }



// // double linkedlist


// #include <iostream>
// using namespace std;

// // Minimal Node structure with a single constructor
// struct Node {
//     int data;
//     Node* next;
//     Node* prev; // For a doubly linked list

//     // The single constructor
//     Node(int val) {
//         data = val;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// int main() {
//     // 1. Create independent nodes manually using the constructor
//     Node* first = new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);

//     // 2. Link the nodes together sequentially
//     first->next = second;
//     second->prev = first; // For a doubly linked list, you would also set the previous pointer
//     third->prev = second;
//     second->next = third;

//     // 3. Print the list elements sequentially
//     Node* temp = first;     
//     while (temp != nullptr) {
//         cout << temp->data << "  <-> ";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;

//     return 0;
// }


// circular linkedlist


#include <iostream>
using namespace std;

// Minimal Node structure with a single constructor
struct Node {
    int data;
    Node* next;
    Node* prev; // For a doubly linked list

    // The single constructor
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
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
third->next = first; // Making it circular
    // 3. Print the list elements sequentially
    Node* temp = first;     
    while (temp != nullptr) {
        cout << temp->data << "  <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}