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
int identical(Node *root1,Node *root2)
{
  if(root1 == NULL && root2 == NULL)
    return 1;
  if(root1 != NULL && root2 != NULL)
  {
    return(root1 -> data == root2 -> data &&
      identical(root1 -> lc,root2 -> lc) &&
    identical(root1 -> rc,root2 -> rc) );
  }
  return 0;
}
int main()
{
  Node *root1 = new Node(1);
  root1 -> lc = new Node(2);
  root1 -> rc = new Node(3);
  root1 -> lc -> lc = new Node(4);
  root1 ->lc -> rc = new Node(5);
  Node *root2 = new Node(1);
  root2 -> lc = new Node(2);
  root2 -> rc = new Node(3);
  root2 -> lc -> lc = new Node(4);
  root2 ->lc -> rc = new Node(5);
  if(identical(root1,root2))
    cout << "Both the trees are identical.";
  else
    cout << "Both the trees are not identical.";
  return 0;
}
