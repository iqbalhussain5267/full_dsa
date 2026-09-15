// #include <iostream>
// #include <vector>
// using namespace std;

// struct Node
// {
//   int data;
//   Node *left;
//   Node *right;
//   Node(int val)
//   {
//     data = val;
//     left = nullptr;
//     right = nullptr;
//   }
// };

// Node *tree(vector<int> &nums, int &idx)
// {
//   idx++;
//   if (idx >= nums.size() || nums[idx] == -1)
//   {
//     return nullptr;
//   }
//   Node *root = new Node(nums[idx]);
//   root->left = tree(nums, idx);
//   root->right = tree(nums, idx);
//   return root;
// }

// // Reusing your exact isIdentical function
// bool isIdentical(Node *root, Node *root1)
// {
//   if (root == nullptr || root1 == nullptr)
//   {
//     return root == root1;
//   }
//   bool isleftSame = isIdentical(root->left, root1->left);
//   bool isrightSame = isIdentical(root->right, root1->right);
//   return isleftSame && isrightSame && root->data == root1->data;
// }

// // New function to check if subRoot is a subtree of root
// bool isSubtree(Node* root, Node* subRoot)
// {
//   // An empty tree cannot contain a subRoot (assuming subRoot is not null)
//   if (root == nullptr)
//   {
//     return false;
//   }

//   // 1. If current nodes match, verify if the whole structure matches
//   if (root->data == subRoot->data)
//   {
//     if (isIdentical(root, subRoot))
//     {
//       return true;
//     }
//   }

//   // 2. Otherwise, check if subRoot matches any tree down the left or right paths
//   return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
// }

// int main()
// {
//   // Main Tree representation
//   vector<int> mainTreeNodes = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
//   // Subtree representation (matching the right branch: node 3 and its children)
//   vector<int> subTreeNodes = {3, 4, -1, -1, 5, -1, -1};

//   int idx1 = -1;
//   Node *root = tree(mainTreeNodes, idx1);

//   int idx2 = -1;
//   Node *subRoot = tree(subTreeNodes, idx2);

//   bool result = isSubtree(root, subRoot);
//   cout << (result ? "Is a Subtree" : "Not a Subtree") << endl;

//   return 0;
// }

// diamter or longst part between asy two nodes#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

// Start index at 0 to correctly track the vector elements
static int current_index = 0;

Node *buildtree(vector<int> arr)
{
  // Base case: if we out of bounds or hit a -1, it represents a NULL node
  if (current_index >= arr.size() || arr[current_index] == -1)
  {
    current_index++; // Move to the next element for subsequent calls
    return NULL;     // FIXED: Returning NULL instead of nothing
  }

  // Create the root node with the current element
  Node *root = new Node(arr[current_index]);
  current_index++; // Move to the next element before building subtrees

  // Recursively build left and right subtrees
  root->left = buildtree(arr);
  root->right = buildtree(arr);

  return root;
};

void tree(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data<< " "; // Added a space for readable output
  tree(root->left);
  tree(root->right);
}


int height(Node* root){
  if(root==NULL){
    return 0;
  }
  int lefth=height(root->left);
  int righth=height(root->right);
  return max(lefth,righth) +1;
};
int diameter(Node* root){
  if(root==NULL){
    return 0;
  }
  int leftd=diameter(root->left);
  int rightd=diameter(root->right);
  int currd=height(root->left) * height(root->right);
  return max(currd,max(leftd,rightd));
};
// question : kth level of tree k=3
void kthLevel(Node* root,int k){
  if(root==NULL){
    return ;
  }
  if(k==1){
    cout<<root->data<<" ";
    return;
  }
  kthLevel(root->left,k-1);
  kthLevel(root->right,k-1);
}
int main()
{
  // -1 represents NULL placeholders in this preorder traversal array
  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  
  Node *root = buildtree(arr);

//   cout << "Preorder Traversal: ";
  // tree(root);
//   cout << endl;
// cout<<diameter(root);


kthLevel(root,3);
  return 0;
}
