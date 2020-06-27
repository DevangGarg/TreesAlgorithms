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
unsigned int height(Node *root)
{
  unsigned int lh,rh;
  if(root == NULL)
    return 0;
  lh = height(root -> lc);
  rh = height(root -> rc);
  if(lh > rh)
    return (lh + 1);
  else
    return (rh + 1);
}
int main()
{
  Node *root = new Node(1);
  root -> lc = new Node(2);
  root -> rc = new Node(3);
  root -> lc -> lc = new Node(4);
  root ->lc -> rc = new Node(5);
  cout << "Height of the binary tree:" << height(root);
  return 0;
}
