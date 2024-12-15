/*You are given the root of a binary tree.
LEETCODE 1372
A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.*/

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
    int longestZigZag(TreeNode *root)
    {
        int maxZigZag = 0;
        dfs(root, true, 0, maxZigZag);  // Start exploring as if coming from left
        dfs(root, false, 0, maxZigZag); // Start exploring as if coming from right
        return maxZigZag;
    }

private:
    void dfs(TreeNode *node, bool isLeft, int length, int &maxZigZag)
    {
        if (node == nullptr)
            return;
        maxZigZag = max(maxZigZag, length);
        if (isLeft)
        {
            dfs(node->left, false, length + 1, maxZigZag); // Go left, then switch to right
            dfs(node->right, true, 1, maxZigZag);          // Reset length and start as if coming from right
        }
        else
        {
            dfs(node->right, true, length + 1, maxZigZag); // Go right, then switch to left
            dfs(node->left, false, 1, maxZigZag);          // Reset length and start as if coming from left
        }
    }
};

// Helper function to create a binary tree for testing
TreeNode *createTree()
{
    // Example tree:
    //         1
    //          \
    //           1
    //          / \
    //         1   1
    //          \   \
    //           1   1
    //          /
    //         1

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);
    return root;
}

int main()
{
    TreeNode *root = createTree();
    Solution solution;
    cout << "Longest ZigZag Path: " << solution.longestZigZag(root) << endl;
    return 0;
}
