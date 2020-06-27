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
int isSubtree(Node *T,Node *S)
{
  if(S == NULL)
    return 1;
  if(T == NULL)
    return 0;
  if(identical(T,S))
    return 1;
  return isSubtree(T -> lc,S) || isSubtree(T -> rc,S);
}
int main()
{
  Node *T = new Node(26);
  T -> rc = new Node(3);
  T -> rc -> rc = new Node(3);
  T -> lc = new Node(10);
  T -> lc -> lc = new Node(4);
  T -> lc -> rc = new Node(6);
  T -> lc -> lc -> rc = new Node(30);
  Node *S = new Node(10);
  S -> lc = new Node(4);
  S -> rc = new Node(6);
  S -> lc -> rc = new Node(30);
  if(isSubtree(T,S))
    cout << "S is the subtree of T";
  else
    cout << "S is not the subtree of T";
  return 0;
}
