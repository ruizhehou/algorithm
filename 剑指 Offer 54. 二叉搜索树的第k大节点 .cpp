//
// Created by Ruizhe Hou on 2020/10/13.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode *root, int k) {
        stack<TreeNode *> st;
        int res = 0;
        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->right;
            }
            root = st.top();
            k--;
            if (!k) {
                res = root->val;
                break;
            }
            st.pop();
            root = root->left;
        }
        return res;
    }
};

int main() {
    // BST: [3,1,4,null,2], k=1 => 4
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution sol;
    cout << sol.kthLargest(root, 1) << endl; // 4
    cout << sol.kthLargest(root, 2) << endl; // 3
    return 0;
}