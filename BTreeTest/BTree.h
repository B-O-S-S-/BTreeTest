#pragma once
#include "stdafx.h"

typedef struct B_TreeNode
{
	bool isLeaf;
	char** keys;
	struct B_TreeNode* children;
} BTreeNode;

typedef struct B_Tree
{
	BTreeNode* root;
	unsigned int t; //Verzweigungsgrad
} BTree;
