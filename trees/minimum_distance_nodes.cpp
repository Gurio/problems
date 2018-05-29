/*
 *
 https://leetcode.com/problems/minimum-distance-between-bst-nodes
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

tuple<int, int, int> minDiffInBstHelper (TreeNode* root){
    int min_diff, left_diff, right_diff, min_, max_;
    int min_diff_l, min_left, max_left;
    int min_diff_r, min_right, max_right;
    min_diff_l = min_diff_r = min_left = min_right = left_diff = right_diff = numeric_limits<int>::max();
    max_left = max_right = numeric_limits<int>::min();
    if (!root) {return make_tuple(0, 0, 0);}
    if (root->left) {
        tie(min_diff_l, min_left, max_left) = minDiffInBstHelper(root->left);
        left_diff = root->val - max_left;
    }
    if (root->right) {
        tie(min_diff_r, min_right, max_right) = minDiffInBstHelper(root->right);
        right_diff = min_right - root->val;
    }
    min_ = min({root->val, min_left, min_right}); //? only val and min_left?
    max_ = max({root->val, max_left, max_right}); //? only val and max_right?
    min_diff = min({min_diff_l, min_diff_r, left_diff, right_diff});
    return make_tuple(min_diff, min_, max_);
}

int minDiffInBST(TreeNode* root) {
    int min_diff, min_right, max_left;
    tie(min_diff, min_right, max_left) = minDiffInBstHelper (root);
    return min_diff;
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
    
    int res_1 = minDiffInBST(root);
    cout << res_1 << endl;
    return 0;
}