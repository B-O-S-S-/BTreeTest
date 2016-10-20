#pragma once
#include "stdafx.h"

typedef struct B_TreeNode
{
	bool isLeaf;
	List keys;
	struct B_TreeNode* children;
} BTreeNode;

typedef struct B_Tree
{
	struct B_TreeNode* root;
	unsigned int t; //Verzweigungsgrad
} BTree;

typedef struct B_TreeSearchResult
{
	bool found;
	struct B_TreeNode* node;
	int index;
} BTreeSearchResult;
