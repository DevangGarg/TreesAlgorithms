#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *lc,*rc,*next;
  Node(int data)
  {
    this -> data = data;
    this -> lc = NULL;
    this -> rc = NULL;
    this -> next = NULL;
  }
};
void populateNext(Node *root)
{
  static Node *next = NULL;
  if (root)
  {
      populateNext(root -> rc);
      root -> next = next;
      next = root;
      populateNext(root -> lc);
  }
}
int main()
{
  Node *root = new Node(10);
  root -> lc = new Node(8);
  root -> rc = new Node(12);
  root -> lc -> lc = new Node(3);
  populateNext(root);
  Node *ptr = root -> lc -> lc;
  while(ptr)
  {
    cout << "Next of " << ptr -> data << " is "
    << (ptr -> next ? ptr -> next -> data : -1) << endl;
    ptr = ptr -> next;
  }
  return 0;
}
