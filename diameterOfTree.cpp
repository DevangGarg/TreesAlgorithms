#include <iostream>
#include <queue>
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
int height(Node *root)
{
  if(root == NULL)
    return 0;
  queue<Node *> q;
  q.push(root);
  int h = 0;
  while(1)
  {
    int nodeCount = q.size();
    if(nodeCount == 0)
      return h;
    h ++;
    while(nodeCount > 0){
    Node * temp = q.front();
    q.pop();
    if(temp -> lc != NULL)
      q.push(temp -> lc);
    if(temp -> rc != NULL)
      q.push(temp -> rc);
    nodeCount --;
  }
}
}
int max(int a,int b)
{
  return ((a > b ? a : b));
}
int diameter(Node *root)
{
  if(root == NULL)
    return 0;
  int lh,rh,ld,rd;
  lh = height(root -> lc);
  rh = height(root -> rc);
  ld = diameter(root -> lc);
  rd = diameter(root -> rc);
  return max(lh + rh +1,max(ld,rd));
}
int main()
{
  Node *root = new Node(1);
  root -> lc = new Node(2);
  root -> rc = new Node(3);
  root -> lc -> lc = new Node(4);
  root ->lc -> rc = new Node(5);
  cout << "Diameter of the binary tree:" << diameter(root);
  return 0;
}
