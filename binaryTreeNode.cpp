//
// Created by waterwoo on 2021/9/28.
//

#include "binaryTreeNode.h"

using namespace std;

void binaryTreeNode::preOrder(TreeNode *root, vector<int> &res){
    if (root == nullptr)
        return;
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

void binaryTreeNode::inOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr)
        return;
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
}

void binaryTreeNode::postOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr)
        return;
    inOrder(root->left, res);
    inOrder(root->right, res);
    res.push_back(root->val);
}


vector<int> binaryTreeNode::preorderTraversal(TreeNode* root) {
    vector<int> res;
    preOrder(root, res);
    return res;
}

void binaryTreeNode::levelOrder(TreeNode *root, vector<int> &res) {

}
