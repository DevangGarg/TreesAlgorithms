#include <iostream>
#include <cmath>
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
int max(int a,int b)
{
  return ((a > b ? a : b));
}
int height(Node *root)
{
  if(root == NULL)
    return 0;
  return 1 + max(height(root -> lc),height(root -> rc));
}
int isBalanced(Node *root)
{
  if(root == NULL)
    return 1;
  int lh,rh;
  lh = height(root -> lc);
  rh = height(root -> rc);
  if(abs(lh - rh) <= 1 && isBalanced(root -> lc) &&
    isBalanced(root -> rc))
    return 1;
  return 0;
}
int main()
{
  Node *root = new Node(1);
  root -> lc = new Node(2);
  root -> rc = new Node(3);
  root -> lc -> lc = new Node(4);
  root -> lc -> lc -> rc = new Node(5);
  if(isBalanced(root))
    cout << "The tree is balanced.";
  else
    cout << "The tree is not balanced.";
  return 0;
}
