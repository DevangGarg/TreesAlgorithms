#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *rc,*lc;
  Node(int data)
  {
    this -> data = data;
    this -> lc = NULL;
    this -> rc = NULL;
  }
};
Node* lowestCommonAncestor(Node *root,int a,int b)
{
  if(root == NULL)
    return NULL;
  if(root -> data > a && root -> data > b)
    return lowestCommonAncestor(root -> lc,a,b);
  if(root -> data < a && root -> data < b)
    return lowestCommonAncestor(root -> rc,a,b);
  return root;
}
int main()
{
  Node *root = new Node(20);
  root -> lc = new Node(8);
  root -> rc = new  Node(22);
  root -> lc -> lc = new Node(4);
  root -> lc -> rc = new Node(12);
  root -> lc -> rc -> lc = new Node(10);
  root -> lc -> rc -> rc = new Node(14);
  int a = 10,b = 14;
  Node *t = lowestCommonAncestor(root,a,b);
  cout << "Lowest Common Ancestor of  " <<
  a << " and " << b << " is: " << t -> data;
  return 0;
}
