// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* child;

//     Node(int val) {
//         data = val;
//         next = nullptr;
//         child = nullptr;
//     }
// };

// void printList(Node* head) {
//     while (head != nullptr) {
//         cout << head->data;

//         if (head->next != nullptr)
//             cout << " -> ";

//         head = head->next;
//     }

//     cout << endl;
// }

// class Solution {
// public:

//     Node* flatten(Node* head) {

//         if (head == NULL) {
//             return head;
//         }

//         Node* curr = head;

//         while (curr != NULL) {

//             if (curr->child != NULL) {

//                 // Save the next node
//                 Node* next = curr->next;

//                 // Put child list after curr
//                 curr->next = flatten(curr->child);

//                 // Remove child pointer
//                 curr->child = NULL;

//                 // Find the tail of child list
//                 while (curr->next != NULL) {
//                     curr = curr->next;
//                 }

//                 // Attach original next after child list
//                 if (next != NULL) {
//                     curr->next = next;
//                 }
//             }

//             curr = curr->next;
//         }

//         return head;
//     }
// };

// int main() {

//     // Main list
//     Node* head = new Node(1);

//     head->next = new Node(2);
//     head->next->next = new Node(3);
//     head->next->next->next = new Node(4);
//     head->next->next->next->next = new Node(5);

//     // Child list of node 2
//     head->next->child = new Node(6);
//     head->next->child->next = new Node(7);

//     /*
//         Before flatten:

//         1 -> 2 -> 3 -> 4 -> 5
//              |
//              6 -> 7
//     */

//     cout << "Before flatten: ";
//     printList(head);

//     Solution obj;

//     head = obj.flatten(head);

//     /*
//         After flatten:

//         1 -> 2 -> 6 -> 7 -> 3 -> 4 -> 5
//     */

//     cout << "After flatten: ";
//     printList(head);

//     return 0;
// }

// revsrese k node
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node* next;

//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };

// class List
// {
//     Node* head;
//     Node* tail;

// public:

//     List()
//     {
//         head = tail = NULL;
//     }

//     void push(int val)
//     {
//         Node* newNode = new Node(val);

//         if (head == NULL)
//         {
//             head = tail = newNode;
//         }
//         else
//         {
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     Node* reverse(Node* head, int k)
//     {
//         // 1. Reverse first k nodes

//         Node* prev = NULL;
//         Node* curr = head;

//         int count = 0;

//         while (curr != NULL && count < k)
//         {
//             Node* next = curr->next;

//             curr->next = prev;

//             prev = curr;
//             curr = next;

//             count++;
//         }

//         // 2. head is now the last node
//         //    of the reversed group.
//         //
//         //    Connect it to the next reversed group.

//         if (curr != NULL)
//         {
//             head->next = reverse(curr, k);
//         }

//         // prev is the new head
//         return prev;
//     }

//     void reverseK(int k)
//     {
//         head = reverse(head, k);
//     }

//     void print()
//     {
//         Node* temp = head;

//         while (temp != NULL)
//         {
//             cout << temp->data;

//             if (temp->next != NULL)
//                 cout << " -> ";

//             temp = temp->next;
//         }

//         cout << endl;
//     }
// };

// int main()
// {
//     List l;

//     int k = 2;

//     l.push(12);
//     l.push(2);
//     l.push(1);
//     l.push(102);

//     cout << "Before: ";
//     l.print();

//     l.reverseK(k);

//     cout << "After:  ";
//     l.print();

//     return 0;
// }


// swap two nodes
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node* head;
    Node* tail;

public:

    List()
    {
        head = tail = NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    Node* swap(Node* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node* first = head;
        Node* second = head->next;
        Node* prev = NULL;

        while (first != NULL && second != NULL)
        {
            Node* third = second->next;

            // Swap first and second
            second->next = first;
            first->next = third;

            // Connect previous pair
            if (prev != NULL)
            {
                prev->next = second;
            }
            else
            {
                // First swap changes the head
                head = second;
            }

            // Move to next pair
            prev = first;
            first = third;

            if (third != NULL)
            {
                second = third->next;
            }
            else
            {
                second = NULL;
            }
        }

        return head;
    }

    void swapPairs()
    {
        head = swap(head);
    }

    void print()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    List l;

    l.push(12);
    l.push(2);
    l.push(1);
    l.push(102);

    cout << "Before: ";
    l.print();

    l.swapPairs();

    cout << "After:  ";
    l.print();

    return 0;
}