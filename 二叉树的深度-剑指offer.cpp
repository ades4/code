#define _CRT_SECURE_NO_WARNINGS 1 
/*
二叉树的深度 
递归
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int lift = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return lift > right ? lift + 1 : right + 1;
	}
};