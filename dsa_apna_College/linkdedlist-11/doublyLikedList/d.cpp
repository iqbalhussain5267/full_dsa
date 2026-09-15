#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

class List
{
public:
  Node *head; // Made public to easily pass heads into the merge function
  Node *tail;
  List()
  {
    head = tail = NULL;
  }

  // Insert at the front (Note: results will be reversed)
  void push_front(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }
  void push_back(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }
  void pop_front()
  {
    if (head == NULL)
    {
      cout << "list is empty";
      return;
    }
    Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
      head->prev = NULL;
    }
    else
    {
      tail = NULL; // If the list is now empty, update tail too
    }

    temp->next = NULL;
    delete temp;
  }
void pop_back() {
    // 1. Check if the list is empty
    if (head == NULL) { 
        cout << "list is empty"; 
        return; 
    } 

    Node* temp = tail; // Keep track of the node to delete

    // 2. Move tail backwards
    tail = tail->prev; 

    // 3. Update pointers
    if (tail != NULL) { 
        tail->next = NULL; // Disconnect the old last node
    } else { 
        head = NULL; // If the list had only 1 node, it is now empty
    } 

    // 4. Free memory
    temp->prev = NULL; 
    delete temp; 
}

  // Helper to print any given chain of nodes
  void printList()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " <-> ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  List l;
  l.push_front(1);
  l.push_front(4);
  l.push_front(56);
  l.push_front(16);
  // l.push_back(9000);

  // l.pop_front();
  l.pop_back();
  l.printList();
  return 0;
}
