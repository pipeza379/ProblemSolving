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
    TreeNode *before;

    TreeNode(ValueType val, TreeNode *left = 0, TreeNode *right = 0, TreeNode *before = 0)
        : val(val), left(left), right(right), before(before) {}
};

void insert(TreeNode *&node, TreeNode *&bef, ValueType data)
{
    if (node == NULL)
    {
        node = new TreeNode(data);
        node->before = node;
    }
    if (node->val < data)
        insert(node->right, node, data);
    else if (node->val > data)
        insert(node->left, node, data);
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

void del(TreeNode *&node, TreeNode *&bef, ValueType data)
{
    if (!first)
    {
        if (node->left != 0 && data < node->val)
            del(node->left, node, data);
        if (node->val == data)
        {
            if (node->left == 0 && node->right == 0)
            {
                if (bef->val > data)
                    bef->left = 0;
                else
                    bef->right = 0;
            }
            else if (node->left == 0)
            {
                node->right->before = node->before;
                if (bef->val > data)
                    bef->left = node->right;
                else
                    bef->right = node->right;
            }
            else if (node->right == 0)
            {
                node->left->before = node->before;
                if (bef->val > data)
                    bef->left = node->left;
                else
                    bef->right = node->left;
            }
            else
            {
                if (node->left->val > node->right->val){
                    
                }
            }
            free(node);
        }
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
        else if (s == 2)
        {
            check = false;
            serch(tree, inp);
            if (check)
                printf("%d\n", 1);
            else
                printf("%d\n", 0);
        }
        else if (s == 3)
        {
            del(tree, inp);
        }
    }
}