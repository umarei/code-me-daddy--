/*Given the root of a binary tree, return its maximum depth.
LEETCODE 104
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};

// Helper function to create a binary tree for testing
TreeNode *createTree()
{
    // Example tree:
    //      3
    //     / \
    //    9  20
    //       /  \
    //      15   7

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main()
{
    TreeNode *root = createTree();
    Solution solution;
    cout << "Maximum Depth of Binary Tree: " << solution.maxDepth(root) << endl;
    return 0;
}
