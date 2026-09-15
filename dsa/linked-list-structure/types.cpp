// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int val) : data(val), next(nullptr) {}
// };

// int main() {
//     Node* first = new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);
//     Node* fourth = new Node(50);
//     Node* fifth = new Node(60);
    
//     first->next = second;
//     second->next = third;
//     third->next = fourth; 
//     fourth->next = fifth;

//     // 1. Count the total length
//     Node* temp = first;     
//     int l = 0;
//     while (temp != nullptr) {
//         l++;
//         temp = temp->next;
//     }

//     // 2. RESET temp back to the start of the list
//     temp = first; 

//     // 3. Move to the middle position
//     for (int i = 0; i < l / 2; i++) {
//         temp = temp->next;
//     }

//     cout << "Middle element: " << temp->data << endl;

//     // Free memory
//     delete first; delete second; delete third; delete fourth; delete fifth;
//     return 0;
// }


//  slow and fast pointer 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), next(nullptr) {}
};

int main() {
    // Creating the 5 nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(50);
    Node* fifth = new Node(60);
    
    // Linking the nodes together
    first->next = second;
    second->next = third;
    third->next = fourth; 
    fourth->next = fifth;

    // Initialize both pointers at the start of the list
    Node* slow = first;
    Node* fast = first;

    // Move fast by 2 steps and slow by 1 step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Moves 1 step
        fast = fast->next->next;   // Moves 2 steps
    }

    // When fast reaches the end, slow is exactly at the middle
    cout << "Middle element: " << slow->data << endl;

    // Clean up memory
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
