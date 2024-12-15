/*Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
LEETCODE 872
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
*/

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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }

private:
    void getLeaves(TreeNode *node, vector<int> &leaves)
    {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr)
        {
            leaves.push_back(node->val);
        }
        getLeaves(node->left, leaves);
        getLeaves(node->right, leaves);
    }
};

// Helper function to create a binary tree for testing
TreeNode *createTree1()
{
    // Example tree 1:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 9  8
    //       / \
    //      7   4

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

TreeNode *createTree2()
{
    // Example tree 2:
    //         3
    //        / \
    //       5   1
    //      / \    \
    //     6   7    4
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(4);
    return root;
}

int main()
{
    TreeNode *root1 = createTree1();
    TreeNode *root2 = createTree2();

    Solution solution;
    cout << (solution.leafSimilar(root1, root2) ? "The trees are leaf-similar." : "The trees are not leaf-similar.") << endl;

    return 0;
}
