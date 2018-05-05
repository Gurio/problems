#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <tuple>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void minDiffInBstHelper (TreeNode* root, int& min_diff, int& min_right, int& max_left){
    if (!root) {min_diff = 0; return;}
    int min_diff_ = numeric_limits<int>::max();
    int min_right_ = numeric_limits<int>::max();
    int max_left_ = numeric_limits<int>::min();

    if (!root->left) {
        max_left = max(root->val,max_left);
    } else {
        int dummy;
        minDiffInBstHelper (root->left, min_diff_, min_right_, max_left_);
        int new_diff = root->val - max_left_;
        min_diff = min(min_diff_, new_diff);
        max_left = max(max_left_,root->val);
        cout << "left: " << min_diff_ << " v " << new_diff << " = " << root->val << "-" << max_left_;
    }
    if (!root->right) {
        min_right = min(root->val,min_right);
    } else {
        int dummy;
        minDiffInBstHelper (root->right, min_diff_, min_right_, max_left_);
        int new_diff = min_right_ - root->val;
        min_diff = min(min_diff,min(min_diff_, new_diff));
        min_right = min(min_right_,root->val);
        cout << "right: " << min_diff_ << " v " << new_diff << " = " << min_right_ << "-" << root->val;
    }
    min_right = min(min_right_,root->val);
    max_left = max(max_left_,root->val);
    cout  << "; maxleft: " << max_left << "; minright: " << min_right  << endl;
}

int minDiffInBST(TreeNode* root) {
    int min_diff = numeric_limits<int>::max();
    int min_right = numeric_limits<int>::max();
    int max_left = numeric_limits<int>::min();
    minDiffInBstHelper (root, min_diff, min_right, max_left);
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