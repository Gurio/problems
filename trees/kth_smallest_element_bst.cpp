/*
 *
 https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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

pair<int,int> kthSmallestHelper(TreeNode* root, int k) {
    int kth_smallest;
    if (root->left){
        tie(kth_smallest,k) = kthSmallestHelper(root->left,k);
    }
    if (k>0){
        k--;
        kth_smallest = root->val;
    }
    if (k>0 && root->right){
        tie(kth_smallest,k) = kthSmallestHelper(root->right,k);
    }
    return make_pair(kth_smallest,k);
}

int kthSmallest(TreeNode* root, int k) {
    int kth_smallest;
    tie(kth_smallest, k) = kthSmallestHelper(root, k);
    return kth_smallest;
}

 int main(){
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->left->left = new TreeNode(11);
    root->right->right = new TreeNode(18);
    root->right->right->left = new TreeNode(17);
    root->right->right->right = new TreeNode(20);
    
    int res_1 = kthSmallest(root, 10);
    cout << res_1 << endl;
    return 0;
}