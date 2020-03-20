#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        stack<TreeNode *> node_stack1;
        stack<TreeNode *> node_stack2;
        vector<vector<int>> res;
        node_stack1.push(root);

        while (!node_stack1.empty())
        {
            vector<int> res1;
            while (!node_stack1.empty())
            {
                TreeNode *node = node_stack1.top();
                res1.push_back(node->val);
                node_stack1.pop();
                if (node->left)
                {
                    node_stack2.push(node->left);
                }
                if (node->right)
                {
                    node_stack2.push(node->right);
                }
            }
            if (!res1.empty())
                res.push_back(res1);

            res1.clear();

            while (!node_stack2.empty())
            {
                TreeNode *node = node_stack2.top();
                res1.push_back(node->val);
                node_stack2.pop();

                if (node->right)
                {
                    node_stack1.push(node->right);
                }
                if (node->left)
                {
                    node_stack1.push(node->left);
                }
            }
            if (!res1.empty())
                res.push_back(res1);
            res1.clear();
        
        }
        return res;
    }
};

