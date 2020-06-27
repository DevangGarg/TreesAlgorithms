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
void deleteTree(Node *node)
{
  if(node == NULL)
    return;
  deleteTree(node -> lc);
  deleteTree(node -> rc);
  cout << "Deleting node: " <<  node -> data << endl;
  delete(node);
}
int main()
{
  Node *root = new Node(1);
  root -> lc = new Node(2);
  root -> rc = new Node(3);
  root -> lc -> lc = new Node(4);
  root ->lc -> rc = new Node(5);
  deleteTree(root);
  root = NULL;
  cout << "Tree deleted";
  return 0;
}
