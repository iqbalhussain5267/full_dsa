// #include <iostream>
// using namespace std;

// class Node {
// public:
// int data;
// Node *next;
// Node(int val) {
// data = val;
// next = NULL;
// }
// };

// class Queue {
// Node *head;
// Node *tail;
// public:
// Queue() {
// head = tail = NULL;
// }

// void push(int val) {
// Node *newNode = new Node(val);
// if (empty()) {
// head = tail = newNode;
// } else {
// tail->next = newNode;
// tail = newNode; // Fixed: update tail to the new node
// }
// }

// void pop() {
// if (empty()) {
// cout << " list is empty bhai jan";
// } else {
// Node *temp = head;
// head = head->next;
// if (head == NULL) { // Fixed: reset tail if queue becomes empty
// tail = NULL;
// }
// delete temp;
// }
// }

// int front() {
// if (empty()) {
// cout << "list is empty ";
// return -1; // Return a default value or handle error
// } else {
// return head->data; // Fixed: added return keyword
// }
// }

// bool empty() {
// return head == NULL;
// }
// };

// int main() {
// Queue q;
// q.push(1);
// q.push(10);
// q.push(100);
// while (!q.empty()) {
// cout << " your queue is " << q.front() << " ";
// q.pop();
// }
// return 0;
// }

// using stl

// #include<iostream>
// #include<queue>

// using namespace std;

// int main(){

// queue<int> q;
// q.push(90);
// q.push(9);
// q.push(901);
// while(!q.empty()){
//   cout<<q.front()<<" ";
//   q.pop();
// }
//   return 0;
// }

// deque

// #include <iostream>
// #include <deque>

// using namespace std;

// int main()
// {
//   deque<int> d;
//   d.push_back(12);
//   d.push_back(2);
//   d.push_back(1);
//   d.push_front(90000);
//   cout << d.front() << " " << d.back();
//   return 0;
// }

// circular queue
#include<iostream>
using namespace std;

class circularQueue {
    int* arr;
    int currSize, cap;
    int front;
    int rear;

public:
    circularQueue(int size) {
        cap = size;
        arr = new int[cap];
        // Initialize all slots to -1 so we can visually see empty slots
        for(int i = 0; i < cap; i++) {
            arr[i] = -1; 
        }
        front = 0;
        rear = -1;
        currSize = 0; 
    }

    void push(int data) {
        if (currSize == cap) { 
            cout << "Queue is Full!\n";
            return;
        }
        rear = (rear + 1) % cap; 
        arr[rear] = data;        
        currSize++;              
    }

    void pop() {
        if (empty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        arr[front] = -1; // Optional: Clear the data visually on pop
        front = (front + 1) % cap; 
        currSize--;                
    }

    int getFront() { 
        if (empty()) return -1;
        return arr[front];
    }

    bool empty() {
        return currSize == 0; 
    }

    // Prints raw array layout to prove it is circular
    void display() {
        cout << "Array Layout: [ ";
        for(int i = 0; i < cap; i++) {
            if(arr[i] == -1) cout << "_ "; // Visual placeholder for empty slot
            else cout << arr[i] << " ";
        }
        cout << "] | Front index: " << front << " | Rear index: " << rear << "\n\n";
    }

    ~circularQueue() {
        delete[] arr;
    }
};

int main() {
    // 1. Create a queue of size 3
    circularQueue q(3);
    cout << "--- Initial State ---\n";
    q.display();

    // 2. Fill the queue up
    cout << "--- Pushing 10, 20, 30 ---\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    // 3. Pop one item (removes 10 from index 0)
    cout << "--- Popping 10 (Front moves) ---\n";
    q.pop();
    q.display();

    // 4. Push 40 (This wraps around circularly back to index 0!)
    cout << "--- Pushing 40 (Watch it wrap to index 0!) ---\n";
    q.push(40);
    q.display();

    return 0;
}
