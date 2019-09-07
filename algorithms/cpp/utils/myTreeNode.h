//
// Created by tianm on 2019-09-05.
//


//#include <myTreeNode.cpp>

#pragma once

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void inorderTraversal(TreeNode *root);

void preorderTraversal(TreeNode *root);

void postorderTraversal(TreeNode *root);



//int main() {
////       1
////     /  \
////    2   3
////  /  \
//// 4   5
//    auto *so = new Solution();
//    TreeNode *root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    vector<int> res = so->inorderTraversal(root);
//    for (int &x:res)
//        cout << x << " ";
//    delete so;
//    return 0;
//}



