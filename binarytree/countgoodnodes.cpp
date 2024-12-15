/*Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
LEETCODE 1448
Return the number of good nodes in the binary tree.*/

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
    int goodNodes(TreeNode *root)
    {
        return countGoodNodes(root, INT_MIN);
    }

private:
    int countGoodNodes(TreeNode *node, int maxVal)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int count = 0;
        if (node->val >= maxVal)
        {
            count = 1;
            maxVal = node->val;
        }
        return count + countGoodNodes(node->left, maxVal) + countGoodNodes(node->right, maxVal);
    }
};

// Helper function to create a binary tree for testing
TreeNode *createTree()
{
    // Example tree:
    //         3
    //        / \
    //       1   4
    //      /   / \
    //     3   1   5

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    return root;
}

int main()
{
    TreeNode *root = createTree();
    Solution solution;
    cout << "Number of Good Nodes: " << solution.goodNodes(root) << endl;
    return 0;
}
