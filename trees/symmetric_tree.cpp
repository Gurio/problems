/*
 *
 https://leetcode.com/problems/symmetric-tree
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <tuple>
#include <limits>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricIterative(TreeNode* root) {
    if (!root){return true;}
    TreeNode* left  = root->left;
    TreeNode* right = root->right;
    stack<TreeNode*> left_s;
    stack<TreeNode*> right_s;

    left_s.push(left);
    right_s.push(right);

    while (!left_s.empty() && !right_s.empty()) {
        left = left_s.top(); left_s.pop();
        right = right_s.top(); right_s.pop();
        if (!left && !right) continue;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        left_s.push(left->left);
        right_s.push(right->right);
        left_s.push(left->right);
        right_s.push(right->left);
    }
    return true;left_s.empty() && right_s.empty();
}

bool isSymmetricRecursive(TreeNode* left, TreeNode* right) {
    if (!left && !right){return true;}
    if (!left || !right){return false;}
    bool left_sym = isSymmetricRecursive(left->left, right->right);
    bool right_sym = isSymmetricRecursive(left->right, right->left);
    return left->val==right->val && left_sym && right_sym;
}

bool isSymmetric(TreeNode* root) {
    if (!root){return true;}
    return isSymmetricIterative(root);
    return isSymmetricRecursive(root->left, root->right);
}


int main(){
    //[4,2,6,1,3,null,null]
    // TreeNode *root = new TreeNode(40);
    // root->left = new TreeNode(25);
    // root->left->left = new TreeNode(10);
    // root->left->right = new TreeNode(32);
    // root->right = new TreeNode(60);
    // TreeNode *root = new TreeNode(96);
    // root->left = new TreeNode(12);
    // root->left->right = new TreeNode(13);
    // root->left->right->right = new TreeNode(52);
    // root->left->right->right->left = new TreeNode(29);
    TreeNode *root = new TreeNode(56);
    root->left = new TreeNode(42);
    root->left->left = new TreeNode(23);
    root->left->right = new TreeNode(51);
    root->right = new TreeNode(77);
    root->right->left = new TreeNode(75);
    root->right->left->left = new TreeNode(67);
    root->right->right = new TreeNode(90);
    root->right->right->left = new TreeNode(78);
    root->right->right->right = new TreeNode(99);
    
    int res_1 = isSymmetric(root);
    cout << res_1 << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->left->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    res_1 = isSymmetric(root);
    cout << res_1 << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);

    res_1 = isSymmetric(root);
    cout << res_1 << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(5);

    res_1 = isSymmetric(root);
    cout << res_1 << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(5);

    res_1 = isSymmetric(root);
    cout << res_1 << endl;

    root = new TreeNode(9);
    root->left = new TreeNode(25);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(100);
    root->right = new TreeNode(25);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(9);

    res_1 = isSymmetric(root);
    cout << res_1 << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    res_1 = isSymmetric(root);
    cout << res_1 << endl;
    return 0;
}