#include "stdafx.h"

static const unsigned int VerzweigungsGrad_T = 5;

void* searchBTree(const BTree* bTree, const char* key)
{
	if (bTree == NULL || bTree->root == NULL)
	{
		printf("\nbTree is empty or NULL");
		return NULL;
	}
	else
	{
		BTreeNode* node = bTree->root;
		if (node->isLeaf)
		{

		}
		else
		{
		}
	}
}
