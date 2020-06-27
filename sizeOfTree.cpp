#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *lc,*rc;
  Node(int data)
  {
    this -> data = data;
    this -> lc = NULL;
    this -> rc = NULL;
  }
};
int sizeOfTree(Node *root)
{
  if(root == NULL)
    return 0;
  else
    return sizeOfTree(root -> lc) + 1 + sizeOfTree(root -> rc);
}
int main()
{
  Node *root = new Node(1);
  root -> lc = new Node(2);
  root -> rc = new Node(3);
  root -> lc -> lc = new Node(4);
  root ->lc -> rc = new Node(5);
  cout << "Size of the binary tree:" << sizeOfTree(root);
  return 0;
}
