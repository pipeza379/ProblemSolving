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

void printVal(int data, int count)
{
    while (count--)
        cout << "...";
    cout << "* " << data << endl;
}

void serch(TreeNode *&node, ValueType data, int count)
{
    // cout << node->val;
    if (node->right != 0)
        serch(node->right, data, count + 1);
    printVal(node->val, count);
    if (node->left != 0)
        serch(node->left, data, count + 1);

}

int main()
{
    int r, inp;
    cin >> r;
    TreeNode *tree;
    while (r--)
    {
        cin >> inp;
        if (first)
        {
            tree = new TreeNode(inp);
            first = false;
            continue;
        }
        insert(tree, inp);
    }
    serch(tree, inp, 0);
}