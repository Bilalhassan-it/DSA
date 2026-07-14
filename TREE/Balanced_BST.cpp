#include <iostream>
#include <vector>
#include "BST.cpp"
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BalancedBST {
public:

    TreeNode* helper(const vector<int>& num, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(num[mid]);

        root->left = helper(num, start, mid - 1);
        root->right = helper(num, mid + 1, end);

        return root;
    }

    TreeNode* SortedArrToBST(const vector<int>& num) {
        return helper(num, 0, num.size() - 1);
    }
};