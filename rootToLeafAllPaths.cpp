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
void printArray(int arr[],int n)
{
  for(int i = 0;i < n;i ++)
    cout << arr[i] << " ";
  cout << endl;
}
void printPathsRecur(Node *root,int arr[],int n)
{
  if(root == NULL)
    return;
  arr[n] = root -> data;
  n ++;
  if(root -> lc == NULL && root -> rc == NULL)
  {
    printArray(arr,n);
  }
  printPathsRecur(root -> lc,arr,n);
  printPathsRecur(root -> rc,arr,n);
}
void printPaths(Node *root)
{
  int path[1000];
  printPathsRecur(root,path,0);
}
int main()
{
  Node *root = new Node(1);
  root -> lc = new Node(2);
  root -> rc = new Node(3);
  root -> lc -> lc = new Node(4);
  root -> lc -> rc = new Node(5);
  root -> rc -> lc = new Node(6);
  root -> rc -> rc = new Node(7);
  printPaths(root);
  return 0;
}
