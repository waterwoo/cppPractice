//
// Created by waterwoo on 2021/9/28.
//

#ifndef CPPPRACTICE_BINARYTREENODE_H
#define CPPPRACTICE_BINARYTREENODE_H
#include <vector>


using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class binaryTreeNode {
private:
    void preOrder(TreeNode *root, vector<int> &res);
    void inOrder(TreeNode *root, vector<int> &res);
    void biOrder(TreeNode *root, vector<int> &res);
public:
    vector<int> preorderTraversal(TreeNode* root) ;

};


#endif //CPPPRACTICE_BINARYTREENODE_H
