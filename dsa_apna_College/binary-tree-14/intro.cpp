// #include <iostream>
// #include <vector>

// using namespace std;
// class Node
// {
// public:
//   int data;
//   Node *left;
//   Node *right;
//   Node(int val)
//   {
//     data = val;
//     left = right = NULL;
//   };
// };
// static int idx = -1;
// Node *buildtree(vector<int> preorder)
// {
//   idx++;
//   if (preorder[idx] == -1)
//   {
//     return NULL;
//   }
//   Node *root = new Node(preorder[idx]);
//   root->left = buildtree(preorder);
//   root->right = buildtree(preorder);
//   return root;
// }
// int main()
// {
//   vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
//   Node* root = buildtree(preorder);
//   cout <<"root of the tree is  "<< root->data <<' ';
//   cout <<"root of the left  is  "<< root->left->data <<' ';
//   cout <<"root of the rightis  "<< root->right->data <<' ';

//   return 0;
// }

// traverse

// 1 PRE ORDER
// #include <iostream>
// #include <vector>

// using namespace std;
// class Node
// {
// public:
//   int data;
//   Node *left;
//   Node *right;
//   Node(int val)
//   {
//     data = val;
//     left = right = NULL;
//   };
// };
// static int idx = -1;
// Node *buildtree(vector<int> preorder)
// {
//   idx++;
//   if (preorder[idx] == -1)
//   {
//     return NULL;
//   }
//   Node *root = new Node(preorder[idx]);
//   root->left = buildtree(preorder);
//   root->right = buildtree(preorder);
//   return root;
// }
// void preordertraverse(Node* root){
//   if(root==NULL){
//     return ;
//   }
//   cout<<root->data<<"  ";
//   preordertraverse(root->left);
//   preordertraverse(root->right);
// };
// int main()
// {
//   vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
//   Node* root = buildtree(preorder);
//   preordertraverse(root);
//   cout<<endl;
//   return 0;
// }

// inorder traversal

// left ,root,right
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// class Node
// {
// public:
//   int data;
//   Node *left;
//   Node *right;
//   Node(int val)
//   {
//     data = val;
//     left = right = NULL;
//   }
// };

// static int current_index = -1;

// Node *buildTree(vector<int> &preorder)
// {
//   current_index++;
//   if (current_index >= preorder.size() || preorder[current_index] == -1)
//   {
//     return NULL;
//   }
//   Node *root = new Node(preorder[current_index]);
//   root->left = buildTree(preorder);
//   root->right = buildTree(preorder);
//   return root;
// }

// // Your exact function
// void inordertraverse(Node *root)
// {
//   if (root == NULL)
//   {
//     return;
//   }
//   inordertraverse(root->left);
//   cout << root->data << " ";
//   inordertraverse(root->right);
// }
// // postorder : left.right,root
// void postorder(Node *root)
// {
//   if (root == NULL)
//   {
//     return;
//   }
//   postorder(root->left);
//   postorder(root->right);
//   cout << root->data << " ";
// }
// // level order traversal
// void levelorder(Node *root)
// {
//   queue<Node *> q;
//   q.push(root);
//   while (q.size() > 0)
//   {
//     Node *curr = q.front();
//     q.pop();
//     cout << curr->data << " ";
//     if (curr->left != NULL)
//     {
//       q.push(curr->left);
//     }
//     if (curr->right != NULL)
//     {
//       q.push(curr->right);
//     }
//   }
// };
// void everylevel(Node *root)
// {
//   if (root == NULL) return; // Fix 1: Prevent crash if tree is empty

//   queue<Node *> q;
//   q.push(root);
//   q.push(NULL); // Fix 2: Add the initial NULL marker for the first level

//   while (q.size() > 0)
//   {
//     Node *curr = q.front();
//     q.pop();
//     if (curr == NULL)
//     {
//       if (!q.empty())
//       {
//         cout << endl;
//         q.push(NULL);
//         continue;
//       }
//       else
//       {
//         break;
//       }
//     }
//     cout << curr->data << " ";
//     if (curr->left != NULL)
//     {
//       q.push(curr->left);
//     }
//     if (curr->right != NULL)
//     {
//       q.push(curr->right);
//     }
//   }
// }
// int main()
// {
//   // This preorder sequence creates a specific binary tree structure
//   vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

//   Node *root = buildTree(preorder);

//   cout << "In-order Traversal of the tree: ";
//   inordertraverse(root);
//   cout << endl;
//   cout << "post order traversal : ";
//   postorder(root);
//   cout << endl;
//   cout << "level order tarversal ; ";
//   levelorder(root);
//   cout << endl;
//   cout << "every level";
//   everylevel(root);
//   return 0;
// }

// height of them tree
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// // Definition for a binary tree node
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

// // Global index tracking position in the vector
// int idx = -1;

// // Function to construct the tree
// Node *tree(vector<int> &nums)
// {
//   idx++;

//   // Base case: if index out of bounds or value is -1, return NULL
//   if (idx >= nums.size() || nums[idx] == -1)
//   {
//     return nullptr;
//   }

//   // Create the root node for the current subtree
//   Node *root = new Node(nums[idx]);

//   // Recursively build the left and right subtrees
//   root->left = tree(nums);
//   root->right = tree(nums);

//   return root;
// }

// // Helper function to print tree (Preorder) to verify results
// void printTree(Node *root)
// {
//   if (root == nullptr)
//   {
//     cout << "-1 ";
//     return;
//   }
//   cout << root->data << " ";
//   printTree(root->left);
//   printTree(root->right);
// }

// int height(Node *root)
// {
//   if (root == NULL)
//   {
//     return 0;
//   }
//   int leftHeight = height(root->left);
//   int rightHeight = height(root->right);
//   return max(leftHeight, rightHeight) + 1;
// };
// int count(Node *root)
// {
//   if (root == NULL)
//   {
//     return 0;
//   }
//   int leftcount = count(root->left);
//   int rightcount = count(root->right);
//   return leftcount + rightcount + 1;
// };
// int sum(Node *root)
// {
//   if (root == NULL)
//   {
//     return 0;
//   }
//   int leftsum = sum(root->left);
//   int rightsum = sum(root->right);
//   return leftsum + rightsum + root->data;
// }

// int main()
// {
//   vector<int> nums = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

//   // Build the tree
//   Node *root = tree(nums);

//   // Verify the tree structure
//   // cout << "Constructed Tree (Preorder): ";
//   // printTree(root);
//   // cout << endl;
//   cout << " height  " << height(root) << endl;
//   cout << "count " << endl;
//   cout << count(root);
//   cout << "sum " << endl;
//   cout << sum(root);
//   return 0;
// }

// identical tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

// Pass idx by reference so it updates correctly without using globals
Node *tree(vector<int> &nums, int &idx)
{
  idx++;

  if (idx >= nums.size() || nums[idx] == -1)
  {
    return nullptr;
  }
  Node *root = new Node(nums[idx]);
  root->left = tree(nums, idx);
  root->right = tree(nums, idx);

  return root;
}

void printTree(Node *root)
{
  if (root == nullptr)
  {
    cout << "-1 ";
    return;
  }
  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right);
}

bool isIdentical(Node *root, Node *root1)
{
  if (root == NULL || root1 == NULL)
  {
    return root == root1;
  }
  bool isleftSame = isIdentical(root->left, root1->left);
  bool isrightSame = isIdentical(root->right, root1->right);
  return isleftSame && isrightSame && root->data == root1->data;
}

int main()
{
  vector<int> nums = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  vector<int> nums1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  // Track an index for each individual tree construction
  int idx1 = -1;
  Node *root = tree(nums, idx1);

  int idx2 = -1;
  Node *root1 = tree(nums1, idx2);
  
  bool result = isIdentical(root, root1);
  cout << (result ? "Identical" : "Not Identical") << endl;

  return 0;
}
