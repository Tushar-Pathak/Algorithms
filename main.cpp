/*
  In this first method, To find lowest common ancestor of two nodes, we find path to first node in the tree and then path to second node in the tree and then we find common nodes from the two path untill first mismatch occurs. The node at which first mismatch occurs is our answer.
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
  struct Node *left;
  int info;
  struct Node *right;
};

typedef struct Node Node;
Node *root = NULL;

void insert_node(int info, Node *node, Node *ptr)
{
  if (node->info == info)
  {
    cout << endl
         << "Duplicate Key Entered from catch 2" << endl;
    return;
  }

  if (node->info > info)
  {
    if (node->left == NULL)
    {
      node->left = ptr;
    }
    else
    {
      insert_node(info, node->left, ptr);
    }
  }
  else
  {
    if (node->right == NULL)
    {
      node->right = ptr;
    }
    else
    {
      insert_node(info, node->right, ptr);
    }
  }
}

void insert(int n)
{
  Node *ptr = new Node;
  ptr->left = NULL;
  ptr->right = NULL;
  ptr->info = n;

  if (root == NULL)
  {
    root = ptr;
  }
  else
  {
    Node *current = root;

    if (current->info == n)
    {
      cout << endl
           << "Duplicate Key Entered";
    }
    else if (current->info > n)
    {
      if (current->left == NULL)
      {
        current->left = ptr;
      }
      else
      {
        insert_node(n, current->left, ptr);
        return;
      }
    }
    else
    {
      if (current->right == NULL)
      {
        current->right = ptr;
      }
      else
      {
        insert_node(n, current->right, ptr);
        return;
      }
    }
  }
}
/***********************************************************/

/******.Three Traversal Methods are illustrated here.*******/
void Inorder(Node *node)
{
  if (node == NULL)
  {
    return;
  }

  Inorder(node->left);
  cout << node->info << " ";
  Inorder(node->right);
}

void Preorder(Node *node)
{
  if (node == NULL)
  {
    return;
  }

  cout << node->info << " ";
  Preorder(node->left);
  Preorder(node->right);
}

void Postorder(Node *node)
{
  if (node == NULL)
  {
    return;
  }

  Postorder(node->left);
  Postorder(node->right);
  cout << node->info << " ";
}
/*********************************/

/*****.This method returns path to node in which the corresponding nodes are stored in queue.******/
queue<Node *> pathtoX(int n)
{
  queue<Node *> path;

  Node *current = root;

  while (current->info != n)
  {
    path.push(current);
    if (current->info > n)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }

    if (current == NULL)
    {
      queue<Node *> temp;
      return temp;
      break;
    }
  }

  if (current->info == n)
  {
    path.push(current);
  }
  return path;
}

void printPath(queue<Node *> path)
{
  while (!path.empty())
  {
    Node *ptr = path.front();
    path.pop();
    cout << ptr->info << (path.size() == 0 ? " " : " ---> ");
  }
  cout << endl;
}

Node *Lowest_Common_Ancestor(int first, int second)
{
  Node *ptr = NULL;

  queue<Node *> path_to_first = pathtoX(first);
  queue<Node *> path_to_second = pathtoX(second);

  cout << first << " : ";
  printPath(path_to_first);
  cout << second << " : ";
  printPath(path_to_second);

  while (!path_to_first.empty() && !path_to_second.empty())
  {
    Node *temp1 = path_to_first.front();
    Node *temp2 = path_to_second.front();

    if (temp1->info == temp2->info)
    {
      ptr = temp1;
      path_to_first.pop();
      path_to_second.pop();
    }
    else
    {
      break;
    }
  }

  return ptr;
}

int main()
{
  int arr[] = {4, 2, 7, 1, 3, 6, 9, 8, 10};

  for (int x : arr)
  {
    insert(x);
  }

  Node *lca = Lowest_Common_Ancestor(7, 2);

  if (lca == NULL)
  {
    cout << "Element Not Found in Tree";
  }
  else
  {
    cout << lca->info;
  }
  return 0;
}