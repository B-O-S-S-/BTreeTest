#include "stdafx.h"

static const unsigned int VerzweigungsGrad_T = 5;

BTreeSearchResult searchBTree(const BTree* bTree, const char* key)
{
	if (bTree == NULL || bTree->root == NULL)
	{
		printf("\nbTree is empty or NULL");
		BTreeSearchResult result = { .found = false, .node = NULL, .index = -1 };
		return result;
	}
	else
	{
		BTreeNode* node = bTree->root;
		if (node->isLeaf)
		{
			int result = findListItem(node->keys, (void*) key)
		}
		else
		{
		}
	}
}
