#include <bits/stdc++.h>
using namespace std;
struct Node
{
    
    int sum;
    
    pair<int, int> interval; 
    Node *left;              
    Node *right;             
};

void build(vector<int> array, Node *cur_node, int L, int R)
{

    cur_node->interval = make_pair(L, R);
    if (L == R)
    {
        
        cur_node->sum = array[L];
        cur_node->left = NULL;
        cur_node->right = NULL;
        return;
    }
    cur_node->left = new Node;
    cur_node->right = new Node;

    build(array, cur_node->left, L, (L + R) / 2);
    build(array, cur_node->right, (L + R) / 2 + 1, R);

    cur_node->sum = cur_node->left->sum + cur_node->right->sum;

    return;
}


int query(vector<int> array, Node *cur_node, int start, int end)
{

    int L = cur_node->interval.first;
    int R = cur_node->interval.second;

    if (R < start || L > end)
    {
        return 0;
    }

    if (start <= L && end >= R)
    {
        return cur_node->sum;
    }

    int left_index = query(array, cur_node->left, start, end);
    int right_index = query(array, cur_node->right, start, end);

    return left_index + right_index;
}

int main()
{
    
    int n = 5, a, b;
    vector<int> array = {1, 2, 1, 8, 7};

    Node *root = new Node();
    build(array, root, 0, n - 1);
    cout << "Enter the range";
    cin >> a >> b;

    cout << "The sum in the interval is "
         << query(array, root, a, b) << '\n';

    return 0;
}
