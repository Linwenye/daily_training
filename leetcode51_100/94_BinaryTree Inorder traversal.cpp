/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		std::vector<int> res;
		if (!root)
		{
			return res;
		}
		// recursive_traversal(root, res);
		iterate_inorder(root,res);
		return res;
	}

	void recursive_traversal(TreeNode* node, vector<int> &res) {

		if (node->left)
		{	
			recursive_traversal(node->left,res);
		}
		res.push_back(node->val);
		if (node->right)
		{
			recursive_traversal(node->right,res);
		}
	}

	void iterate_inorder(TreeNode* node, std::vector<int> &res){
		std::vector<int> my_stack;
		while(node->left){
			my_stack.push_back(node);
		}
	}
};