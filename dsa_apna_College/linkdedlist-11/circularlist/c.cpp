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

class CircularNode
{
  Node *head;
  Node *tail;

public:
  CircularNode()
  {
    head = tail = NULL;
  }

  void push_front(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
      tail->next = head;
    }
    else
    {
      newNode->next = head;
      head = newNode;    // CRITICAL FIX: Update head to the new front node
      tail->next = head; // Maintain circularity by linking tail to the new head
    }
  }
  void insetAttail(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
      tail->next = head;
    }
    else
    {
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
  }
  void print()
  {
    if (head == NULL)
      return;

    Node *temp = head;
    do
    {
      cout << temp->data << "->";
      temp = temp->next;
    } while (temp != head);
    cout << temp->data << endl;
  }
  void deleteAtHead()
  {
    if (head == NULL)
      return;
    // single node
    else if (head == tail)
    {
      head = tail = NULL;
    }
    else
    {
      Node *temp = head;
      head = head->next;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }
  }
  void deleteAtTail()
  {
    if (head == tail)
      return;
    else if (head == tail)
    {
      head = tail = NULL;
    }
    else
    {
      Node *temp = tail;
      Node *prev = head;
      while (prev->next != tail)
      {
        prev = prev->next;
      }
      tail = prev;
      tail->next = head;
      delete temp;
    }
  }
};

int main()
{
  CircularNode c;
  // c.push_front(12);
  // c.push_front(2);
  // c.push_front(1);
  c.insetAttail(1);
  c.insetAttail(2);
  c.insetAttail(3);
  // c.deleteAtHead();
  c.deleteAtTail();
  c.print();
  return 0;
}