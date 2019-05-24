#include <iostream>

using namespace std;

typedef int ValueType;
bool first = true, found = false;
int count = 0, inp, c_ins = 0, r;

struct TreeNode
{
    ValueType val;
    ValueType num;
    TreeNode *left;
    TreeNode *right;

    TreeNode(ValueType val, ValueType num = 0, TreeNode *left = 0, TreeNode *right = 0)
        : val(val), num(num), left(left), right(right) {}
};

void insert(TreeNode *&node)
{
    if (node == NULL)
    {
        node = new TreeNode(inp);
        node->num += 1;
    }
    if (node->val < inp)
    {
        node->num += 1;
        insert(node->right);
    }
    else if (node->val > inp)
    {
        node->num += 1;
        insert(node->left);
    }
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

// void countTree(TreeNode *&node)
// {
//     // cout << node->val << " : " << node->num << endl;
//     if (node->val <= inp)
//         count++; //count itself
//     if (node->left == 0 && inp < node->val)
//         return;
//     if (node->left != 0 && node->val > inp && node->left->val < inp && node->left->right==0)
//     {
//         count += node->left->num;
//         if (node->left->val < inp)
//             return;
//     }
//     // cout << "choose2\n";
//     else if (node->val <= inp && node->left != 0)
//     {
//         count += node->left->num;
//         if (node->val == inp)
//             return;
//     }
//     // else if (node->left != 0 && node->left->val <= inp)
//     if (node->left != 0 && inp < node->val )
//         countTree(node->left);
//     else if (node->right != 0 && inp > node->val)
//         countTree(node->right);
// }

void countTree(TreeNode *&node)
{
    while (1)
    {
        cout << node->val << " : " << node->num << endl;
        if (node->val <= inp)
            count++; //count itself
        if (node->left == 0 && inp < node->val)
            {cout<< "test1\n";
            break;}
        if (node->left != 0 && node->val > inp && node->left->val < inp && node->left->right == 0)
        {
            cout << "test2\n";
            count += node->left->num;
            if (node->left->val < inp)
                break;
        }
        // cout << "choose2\n";
        else if (node->val <= inp && node->left != 0)
        {
            cout << "test3\n";
            count += node->left->num;
            if (node->val == inp)
                break;
        }
        // else if (node->left != 0 && node->left->val <= inp)
        if (node->left != 0 && inp < node->val)
            node = node->left;
        else if (node->right != 0 && inp > node->val)
            node = node->right;
    }
}

int main()
{
    int r, s;
    cin >> r;
    TreeNode *tree;
    while (r--)
    {
        // ios::sync_with_stdio(false);
        cin >> s >> inp;
        if (s == 1)
        {
            c_ins += 1;
            if (first)
            {
                tree = new TreeNode(inp);
                tree->num += 1;
                first = false;
                continue;
            }
            insert(tree);
        }
        else if (!first && s == 2)
        {
            // cout << "inp: " << c_ins << endl;
            count = 0;
            r = c_ins;
            countTree(tree);
            // inOrder(tree);
            // cout << "\ncount: ";
            cout << c_ins - count << endl;
        }
        else
            cout << 0 << endl;
    }
}