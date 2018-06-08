#pragma once
/*
*
*@author£ºAver Jing
*@description£º
* Given the following classes, implement a default constructor and the necessary copy-control
members.
*@date£ºJune 6, 2018
*
*/

#ifndef EX_13_27_H
#define EX_13_27_H

#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
public:
	TreeNode():value(string()),count(int(1)), left(nullptr), right(nullptr){}
	TreeNode(const TreeNode&);
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
private:
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree() :root(nullptr) {}
	BinStrTree(const BinStrTree&);
	BinStrTree& operator=(const BinStrTree&);
private:
	TreeNode *root;
};

#endif