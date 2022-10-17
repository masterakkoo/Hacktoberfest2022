using namespace std;
#include <bits/stdc++.h>
struct node
{
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
struct info
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};
info largest(node* root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    info lef = largest(root->left);
    info righ = largest(root->right);
    info curr;
    curr.size = lef.size + righ.size + 1;
    if (lef.isBST && righ.isBST && (lef.max < root->data && righ.min > root->data))
    {
        curr.max = max(root->data, max(lef.max, righ.max));
        curr.min = min(root->data, min(lef.min, righ.min));
        curr.ans = 1 + righ.ans + lef.ans;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(righ.ans, lef.ans);
    curr.isBST = false;

    return curr;
}
int main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout << largest(root).ans << " ";
    return 0;
}
// #strategy
// we will use five parameters
// define ina __cpp_structured_bindings
// 1.min
// 2.max
// 3.siz
// 4.ans
// 5 isbst
// is bst will return true if the given tree will be a bst