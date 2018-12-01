#include<iostream>
#include<cmath>

using namespace std;


class node
{
	public:
		int val;
		node* left;
		node* right;
		node(int v):val(v)
		{
			left = NULL;
			right = NULL;
		}
		bool IsBalanced_Solution(node* root);
		int depth_tree(node* root);
};
//判断二叉树是否是平衡二叉树
bool node::IsBalanced_Solution(node* root)
{
	if(!root) return true;
	if(abs(depth_tree(root->left) - depth_tree(root->right)) <= 1) return true;
	return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
}

int node::depth_tree(node* root)
{
	if(!root) return 0;
	return max(1+depth_tree(root->left),1 + depth_tree(root->right));
}