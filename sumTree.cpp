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
int isLeaf(Node *root)
{
  if(root == NULL)
    return 0;
  if(root -> lc != NULL && root -> rc != NULL)
    return 1;
  return 0;
}
int isSumTree(Node *root)
{
  int ls,rs;
  if(root == NULL || isLeaf(root))
    return 1;
  if(isSumTree(root -> lc) && isSumTree(root -> rc))
  {
    if(root -> lc == NULL)
      ls = 0;
    else if(isLeaf(root -> lc))
      ls = root -> lc -> data;
    else
      ls = 2 * (root -> lc -> data);
    if(root -> rc == NULL)
      rs = 0;
    else if(isLeaf(root ->rc))
      rs = root -> rc -> data;
    else
      rs = 2 * (root -> rc -> data);
      return (root -> data == ls + rs);
  }
  return 0;
}
int main()
{
  Node *root = new Node(26);
  root -> lc = new Node(10);
  root -> rc = new Node(3);
  root -> lc -> lc = new Node(4);
  root -> lc -> rc = new Node(6);
  root -> rc -> rc = new Node(3);
  if(isSumTree(root))
    cout << "The given tree is the sum tree.";
  else
    cout << "The given tree is not the sum tree.";
  return 0;
}
