#include <iostream>
#include <cstdio>

using namespace std;

typedef int ValueType;
bool first = true, found = false;
int count = 0, inp, c_ins = 0;

struct TreeNode
{
    ValueType val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(ValueType val, TreeNode *left = 0, TreeNode *right = 0)
        : val(val), left(left), right(right) {}
};

void insert(TreeNode *&node)
{
    if (node == NULL)
        node = new TreeNode(inp);
    if (node->val < inp)
        insert(node->right);
    else if (node->val > inp)
        insert(node->left);
}

// void inOrder(TreeNode *&node)
// {
//     if (node == 0)
//         return;
//     if (node->val == inp)
//         stop = true;
//     inOrder(node->right);
//     if (!stop)
//     {
//         count += 1;
//         // cout << node->val << " ";
//         inOrder(node->left);
//     }
// }

void check(TreeNode *&node)
{
    if (inp == node->val)
        found = true;
    if (node->right != 0)
    {
        if (inp > node->val && inp <= node->right->val)
            found = true;
    }
    if (node->left != 0)
    {
        if (inp < node->val && inp >= node->left->val)
            found = true;
    }
}

void countTree(TreeNode *&node)
{
    if (!first)
    {
        check(node);
        if (node->val > inp)
            count++;
        if (node->right != 0 && node->left != 0)
        {
            // cout << node->val << " : " << node->right->val << ", " << node->left->val << endl;
            countTree(node->right);
            if (inp < node->val)
                countTree(node->left);
        }
        else
        {
            if (node->right != 0)
            {
                // cout << node->val << " : R : " << node->right->val << endl;
                countTree(node->right);
            }
            if (node->left != 0 && inp < node->val)
            {
                // cout << node->val << " : L : " << node->left->val << endl;
                if ((node->left->right == 0 && node->left->left == 0) || node->left->right != 0)
                    countTree(node->left);
                else
                {
                    if (node->left->right != 0)
                        countTree(node->left);
                    else if (inp < node->left->val)
                        countTree(node->left);
                    else if (inp < node->left->val && node->left->right == 0)
                        countTree(node->left);
                }
            }
        }
    }
}

int main()
{
    int r, s;
    scanf("%d\n", &r);
    TreeNode *tree;
    while (r--)
    {
        scanf("%d %d", &s, &inp);
        if (s == 1)
        {
            if (first)
            {
                tree = new TreeNode(inp);
                first = false;
                continue;
            }
            insert(tree);
        }
        else if (!first && s == 2)
        {
            count = 0;
            countTree(tree);
            // inOrder(tree);
            // cout << "\ncount: ";
            printf("%d\n", count);
        }
        else
            printf("0\n");
    }
}