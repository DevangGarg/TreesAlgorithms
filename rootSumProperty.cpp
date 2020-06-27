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
int rootSum(Node *root)
{
  if(root == NULL)
    return 1;
  if(root != NULL && (root -> lc == NULL && root -> rc == NULL))
    return 1;
  int a = 0,b = 0;
  if(root -> lc != NULL)
    a = root -> lc -> data;
  if(root -> rc != NULL)
    b = root -> rc -> data;
  if(root -> data == a + b &&
    rootSum(root -> lc) &&
    rootSum(root -> rc))
    return 1;
  return 0;
}
int main()
{
  Node *root = new Node(15);
  root -> lc = new Node(8);
  root -> rc = new Node(7);
  root -> lc -> lc = new Node(3);
  root -> lc -> rc = new Node(5);
  root -> rc -> lc = new Node(7);
  if(rootSum(root))
    cout << "The root sum property is followed.";
  else
    cout << "The property is not followed.";
  return 0;
}
