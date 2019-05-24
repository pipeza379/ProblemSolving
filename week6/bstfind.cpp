#include <iostream>
#include <cstdio>

using namespace std;

typedef int ValueType;
bool first = true;
bool check;

struct TreeNode
{
    ValueType val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(ValueType val, TreeNode *left = 0, TreeNode *right = 0)
        : val(val), left(left), right(right) {}
};

void insert(TreeNode *&node, ValueType data)
{
    if (node == NULL)
        node = new TreeNode(data);
    if (node->val < data)
        insert(node->right, data);
    else if (node->val > data)
        insert(node->left, data);
}

void serch(TreeNode *&node, ValueType data)
{
    // cout << node->val;
    if (!first)
    {
        if (node->left != 0 && data < node->val)
            serch(node->left, data);
        if (node->val == data)
            check = true;
        if (node->right != 0 && data > node->val)
            serch(node->right, data);
    }
}

int main()
{
    int r, s, inp;
    cin >> r;
    TreeNode *tree;
    while (r--)
    {
        scanf("%d %d", &s, &inp);
        // cin >> s >> inp;
        if (s == 1)
        {
            if (first)
            {
                tree = new TreeNode(inp);
                first = false;
                continue;
            }
            insert(tree, inp);
        }
        else
        {
            check = false;
            serch(tree, inp);
            if (check)
                // cout << 1 << endl;
                printf("%d\n", 1);
            else
                printf("%d\n", 0);
            // cout << 0 << endl;
        }
    }
}