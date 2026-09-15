// // reverseLinked list
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//   int data;
//   Node *next;
//   Node(int val)
//   {
//     data = val;
//     next = NULL;
//   }
// };
// class List
// {
//   Node *head;
//   Node *tail;

// public:
//   List()
//   {
//     head = tail = NULL;
//   }
//   void push_front(int val)
//   {
//     Node *newNode = new Node(val);
//     if (head == NULL)
//     {
//       head = tail = newNode;
//       return;
//     }
//     else
//     {
//       newNode->next = head;
//       head = newNode;
//     }
//   }
//   void print()
//   {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//       cout << temp->data << "->";
//       temp = temp->next;
//     }
//     cout << "NULL" << endl;
//   }
//   void reverse()
//   {
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *next = NULL;
//     while (curr != NULL)
//     {
//       next = curr->next;
//       // current next pointing back eg from 8 -> 0 to 0 -> 8
//       curr->next = prev;
//       prev = curr;
//       curr = next;
//     }
//     head = prev;
//   }
// };
// int main()
// {
//   List l1;
//   l1.push_front(12);
//   l1.push_front(5);
//   l1.push_front(3);
//   l1.push_front(0);
//   l1.push_front(8);
//   l1.print();
//   l1.reverse();
//   l1.print();
//   return 0;
// }

// middle through slow and fast pointer
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *next;
//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// class List {
//     Node *head;
//     Node *tail;

// public:
//     List() {
//         head = tail = NULL;
//     }

//     void push_front(int val) {
//         Node *newNode = new Node(val);
//         if (head == NULL) {
//             head = tail = newNode;
//             return;
//         } else {
//             newNode->next = head;
//             head = newNode;
//             // tail still points to the very first node inserted, which is correct here.
//         }
//     }

//     void print() {
//         Node *temp = head;
//         while (temp != NULL) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl; // Added for cleaner formatting
//     }

//     // Fixed: Removed unused parameter and added printing functionality
//     void printMiddle() {
//         if (head == NULL) {
//             cout << "List is empty." << endl;
//             return;
//         }

//         Node* slow = head;
//         Node* fast = head;

//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         cout << "Middle element: " << slow->data << endl;
//     }
// };

// int main() {
//     List l2;
//     l2.push_front(1);
//     l2.push_front(2);
//     l2.push_front(3);

//     cout << "Current List: ";
//     l2.print();

//     l2.printMiddle();

//     return 0;
// }

// detect cycle
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//   int data;
//   Node *next;
//   Node(int val)
//   {
//     data = val;
//     next = NULL;
//   }
// };

// class List
// {
//   Node *head;
//   Node *tail;

// public:
//   List()
//   {
//     head = tail = NULL;
//   }

//   void push_front(int val)
//   {
//     Node *newNode = new Node(val);
//     if (head == NULL)
//     {
//       head = tail = newNode;
//       return;
//     }
//     else
//     {
//       newNode->next = head;
//       head = newNode;
//       // tail still points to the very first node inserted, which is correct here.
//     }
//   }
//   void detectCycle()
//   {
//     Node *slow = head;
//     Node *fast = head;
//     bool hasCycle = false;

//     // Both pointers must move inside the loop braces
//     while (fast != NULL && fast->next != NULL)
//     {
//       slow = slow->next;       // Moves 1 step
//       fast = fast->next->next; // Moves 2 steps

//       if (slow == fast)
//       {
//         hasCycle = true;
//         break; // Cycle found, exit the loop safely
//       }
//     }

//     if (hasCycle)
//     {
//       cout << " yess cycle detected" << endl;
//     }
//     else
//     {
//       cout << "not cycle detecetd" << endl;
//     }
//   }

//   void makeCycle(int pos)
//   {
//     if (head == NULL)
//       return;

//     Node *temp = head;
//     Node *cycleNode = NULL;
//     int index = 0;

//     // 1. Traverse to the end of the list while finding the node at 'pos'
//     while (temp->next != NULL)
//     {
//       if (index == pos)
//       {
//         cycleNode = temp; // This is the node we want to loop back to
//       }
//       temp = temp->next;
//       index++;
//     }

//     // Check if the final node matched the position
//     if (index == pos)
//     {
//       cycleNode = temp;
//     }

//     // 2. Connect the last node's next pointer to the cycle node
//     if (cycleNode != NULL)
//     {
//       temp->next = cycleNode;
//       tail = temp; // Keep the tail pointer updated
//       cout << "Cycle created successfully at value: " << cycleNode->data << endl;
//     }
//     else
//     {
//       cout << "Invalid position! Cycle not created." << endl;
//     }
//   }

//   void print()
//   {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//       cout << temp->data << " ";
//       temp = temp->next;
//     }
//     cout << endl; // Added for cleaner formatting
//   }
// };

// int main()
// {
//   List l2;
//   l2.push_front(1);
//   l2.push_front(2);
//   l2.push_front(3);
//   l2.print();
//   l2.makeCycle(0);

//   l2.detectCycle();

//   return 0;
// }

// delete cycle
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *next;
//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// class List {
//     Node *head;
//     Node *tail;

// public:
//     List() {
//         head = tail = NULL;
//     }

//     void push_front(int val) {
//         Node *newNode = new Node(val);
//         if (head == NULL) {
//             head = tail = newNode;
//             return;
//         } else {
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     // ADDED: Added this function back so main() doesn't fail compilation
//     void detectCycle() {
//         Node *slow = head;
//         Node *fast = head;
//         bool hasCycle = false;

//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) {
//                 hasCycle = true;
//                 break;
//             }
//         }

//         if (hasCycle) {
//             cout << "yess cycle detected" << endl;
//         } else {
//             cout << "not cyce detecetd" << endl;
//         }
//     }

//     void deleteCycle() {
//         Node* slow = head;
//         Node* fast = head;
//         bool hasCycle = false;

//         // Step 1: Detect if a cycle exists
//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast) {
//                 hasCycle = true;
//                 break;
//             }
//         }

//         // If there is no cycle, nothing needs to be deleted
//         if (!hasCycle) {
//             cout << "No cycle found to delete." << endl;
//             return;
//         }

//         // Step 2: Find the starting node of the cycle
//         slow = head;

//         // Special Case: The cycle loops back to the very first node (head)
//         if (slow == fast) {
//             while (fast->next != slow) {
//                 fast = fast->next;
//             }
//             fast->next = NULL;
//             tail = fast;
//             cout << "Cycle deleted successfully (broken at head)." << endl;
//             return;
//         }

//         // General Case: Move both pointers at equal speed until they meet
//         while (slow->next != fast->next) {
//             slow = slow->next;
//             fast = fast->next;
//         }

//         // Step 3: Break the cycle
//         fast->next = NULL;
//         tail = fast;
//         cout << "Cycle deleted successfully." << endl;
//     }

//     void makeCycle(int pos) {
//         if (head == NULL) return;
//         Node *temp = head;
//         Node *cycleNode = NULL;
//         int index = 0;

//         while (temp->next != NULL) {
//             if (index == pos) {
//                 cycleNode = temp;
//             }
//             temp = temp->next;
//             index++;
//         }
//         if (index == pos) {
//             cycleNode = temp;
//         }

//         if (cycleNode != NULL) {
//             temp->next = cycleNode;
//             tail = temp;
//             cout << "Cycle created successfully at value: " << cycleNode->data << endl;
//         } else {
//             cout << "Invalid position! Cycle not created." << endl;
//         }
//     }

//     void print() {
//         Node *temp = head;
//         while (temp != NULL) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     List l2;
//     l2.push_front(1);
//     l2.push_front(2);
//     l2.push_front(3);

//     cout << "Creating a cycle..." << endl;
//     l2.makeCycle(1); // 3 -> 2 -> 1 -> loops back to 2
//     l2.detectCycle();

//     cout << "\nBreaking the cycle..." << endl;
//     l2.deleteCycle();
//     l2.detectCycle();

//     cout << "\nPrinting list safely after deletion:" << endl;
//     l2.print();
//     return 0;
// }

// merge two sorted list
#include <iostream> 
using namespace std; 

class Node { 
public: 
    int data; 
    Node *next; 
    
    Node(int val) { 
        data = val; 
        next = NULL; 
    } 
}; 

class List { 
public: 
    Node *head; // Made public to easily pass heads into the merge function

    List() { 
        head = NULL; 
    } 

    // Insert at the front (Note: results will be reversed)
    void push_front(int val) { 
        Node *newNode = new Node(val); 
        if (head == NULL) { 
            head = newNode; 
        } else { 
            newNode->next = head; 
            head = newNode; 
        } 
    } 

    // Your recursive merge function
    Node* twoMergeNode(Node* h1, Node* h2) { 
        if (h1 == NULL || h2 == NULL) { 
            return h1 == NULL ? h2 : h1; 
        } 
        
        if (h1->data <= h2->data) { 
            h1->next = twoMergeNode(h1->next, h2); 
            return h1; 
        } else { 
            h2->next = twoMergeNode(h1, h2->next); 
            return h2; 
        } 
    } 

    // Helper to print any given chain of nodes
    void printList(Node* startNode) { 
        Node *temp = startNode; 
        while (temp != NULL) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
        cout << endl; 
    } 
}; 

int main() { 
    List l1; 
    List l2; 
    List merger; // Used to call the merge utility

    // Create List 1 (Sorted: 1 -> 3 -> 5)
    // We push back-to-front because push_front reverses input order
    l1.push_front(5); 
    l1.push_front(3); 
    l1.push_front(1); 

    // Create List 2 (Sorted: 2 -> 4 -> 6)
    l2.push_front(6); 
    l2.push_front(4); 
    l2.push_front(2); 

    // Print separate lists
    cout << "List 1: "; 
    l1.printList(l1.head); 

    cout << "List 2: "; 
    l2.printList(l2.head); 

    // Merge lists together
    Node* mergedHead = merger.twoMergeNode(l1.head, l2.head); 

    // Print the final result
    cout << "Merged List: "; 
    merger.printList(mergedHead); 

    return 0; 
}
