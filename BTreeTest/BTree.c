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
	else // tree not empty
	{
		BTreeNode* node = bTree->root;
		
		while(!node->isLeaf) // not a leaf
		{
			CPData* pcpData = &key;
			int index = findEqualOrFirstLargerListItem(&(node->keys), pcpData);
			if (index >= 0)
			{
				int compKeys = strcmp(*pcpData, key);
				if (compKeys == 0)
				{
					BTreeSearchResult result = { .found = true, .node = node, .index = index };
					return result;
				}
				else if (compKeys > 0)// larger key was found -> search in child[index]
				{
					node = &(node->children[index]);
				}
				else // invalid key returned
				{
					printf("\nInvalid key returned from key list.");
					BTreeSearchResult result = { .found = false, .node = NULL, .index = -1 };
					return result;
				}
			}
			else // key is larger than all keys in this node -> search in last child
			{
				node = &(node->children[node->keys.count]);
			}
		}
		// node is leaf
		int index = findListItem(&(node->keys), (void*)key);
		BTreeSearchResult result;
		if (index != -1)
		{
			BTreeSearchResult result = { .found = true, .node = node, .index = index };
			return result;
		}
		else // didn't find key in leaf
		{
			BTreeSearchResult result = { .found = false, .node = NULL, .index = -1 };
			return result;
		}
	}
}
