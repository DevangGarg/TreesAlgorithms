#include <iostream>
using namespace std;
#define bool int
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
bool hasPathSum(Node *root,int sum)
{
  if(root == NULL)
  {
    return (sum == 0);
  }
  else
  {
    bool ans = 0;
    int subSum = sum - root -> data;
    if(subSum == 0 && root -> lc == NULL && root -> rc == NULL)
      return 1;
    if(root -> lc)
      ans = ans || hasPathSum(root -> lc,subSum);
    if(root -> rc)
      ans = ans || hasPathSum(root -> rc,subSum);
    return ans;
  }
}
int main()
{
  int sum = 21;
  Node *root = new Node(10);
  root -> lc = new Node(8);
  root -> rc = new Node(2);
  root -> lc -> lc = new Node(3);
  root -> lc -> rc = new Node(5);
  root -> rc -> lc = new Node(2);
  if(hasPathSum(root,sum))
    cout << "There is a root to leaf path sum with sum = " << sum;
  else
    cout << "There is no such sum.";
  return 0;
}
