#include "ex13_28.h"

TreeNode::TreeNode(const TreeNode &rhs)
{
	value = rhs.value;
	count = rhs.count;
	left = new TreeNode(*rhs.left);
	right = new TreeNode(*rhs.right);
}

TreeNode & TreeNode::operator=(const TreeNode &rhs)
{
	auto lvalue = new TreeNode(*rhs.left);
	auto rvalue = new TreeNode(*rhs.right);
	if (left)
		delete left;
	if (right)
		delete right;
	left = lvalue;
	right = rvalue;
	value = rhs.value;
	count = rhs.count;
}

TreeNode::~TreeNode()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

BinStrTree::BinStrTree(const BinStrTree& rhs)
{
	root = new TreeNode(*rhs.root);
}

BinStrTree & BinStrTree::operator=(const BinStrTree &rhs)
{
	auto temp = new TreeNode(*rhs.root);
	if (root)
		delete root;
	root = temp;
	return *this;
}
