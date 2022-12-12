#include <bits/stdc++.h>
using namespace std;
// class representing the node of interval tree
class Node
{
public:
    int l, r, max;
    Node *left;
    Node *right;
    Node(int lVal, int rVal)
    {
        l = lVal;
        r = rVal;
        max = rVal;
        left = right = NULL;
    }
};
// Function to create a new Node
Node *newNode(int l, int r)
{
    Node *node = new Node(l, r);
    return node;
}
// Function to insert an interval in interval tree
Node *insert(Node *root, int l, int r)
{
    if (root == NULL)
    {
        return newNode(l, r);
    }

    if (l < root->l)
    {
        root->left = insert(root->left, l, r);
    }
    else if (l > root->l)
    {
        root->right = insert(root->right, l, r);
    }
    else
    {
        if (r < root->r)
        {
            root->left = insert(root->left, l, r);
        }
        else
        {
            root->right = insert(root->right, l, r);
        }
    }

    // If current node's max is less than r, then update max
    if (root->max < r)
    {
        root->max = r;
    }

    return root;
}
bool checkOverlap(Node *root, int l, int r)
{
    // If current node is null, return false
    if (root == NULL)
    {
        return false;
    }

    // If overlaps return true
    if (root->l <= r && l <= root->r)
    {
        return true;
    }

    // If max value of current is greater than starting point of I(l)
    // search in left subtree
    if (root->left != NULL && root->left->max >= l)
    {
        return checkOverlap(root->left, l, r);
    }

    // Else search in right subtree
    return checkOverlap(root->right, l, r);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 5, 10);
    root = insert(root, 3, 8);
    root = insert(root, 10, 15);
    root = insert(root, 16, 18);
    root = insert(root, 9, 11);
    root = insert(root, 1, 1);

    if (checkOverlap(root, 1, 2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (checkOverlap(root, 7, 11))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (checkOverlap(root, 20, 25))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
