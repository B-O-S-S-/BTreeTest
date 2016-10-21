#include "stdafx.h"

bool addListItem(List* list, CPData data)	// add an item into a sorted list, smallest item first
{
	if (list != NULL && data != NULL)
	{
		ListItem* current = list->first;
		ListItem* prev = NULL;
		while (current != NULL)
		{
			int compared = list->compareData(current->data, data);
			if (compared < 0) // insert somewhere behind current
			{
				prev = current;
				current = current->next;
			}
			else if (compared > 0) // proceeded far enough, insert right before current
			{
				ListItem tempNewItem = { .data = data, .prev = current->prev, .next = current };
				ListItem* pNewItem = malloc(sizeof(*pNewItem));
				if (pNewItem == NULL)
					abort();
				memcpy(pNewItem, &tempNewItem, sizeof(pNewItem));
				
				current->prev = pNewItem;
				if (prev == NULL) // new head
				{
					list->first = pNewItem;
				}
				else
				{
					prev->next = pNewItem;
				}
				list->count++;
				return true; // item inserted before the end
			}
			else // item already present
			{
				return false;
			}
		}
		ListItem tempNewItem = { .data = data, .prev = prev, .next = NULL };
		ListItem* pNewItem = malloc(sizeof(*pNewItem));
		if (pNewItem == NULL)
			abort();
		memcpy(pNewItem, &tempNewItem, sizeof(pNewItem));
		if (prev == NULL) // empty list
		{
			list->first = pNewItem;
		}
		else // reached end of nonempty list
		{
			prev->next = pNewItem;
		}
		list->count++;
		return true;
	}
	else
	{
		return false;
	}
}

bool removeListItem(List* list, CPData data)
{
	if (list != NULL && data != NULL)
	{
		ListItem* current = list->first;
		while (current != NULL)
		{
			if (list->compareData(current->data, data) == 0)
			{
				if (current->next != NULL)
				{
					current->next->prev = current->prev;
				}
				if (current->prev == NULL) // remove head
				{
					list->first = current->next;
				}
				else // remove middle or tail
				{
					current->prev->next = current->next;
				}
				free(current);
				list->count--;
				return true;
			}
			current = current->next;
		}
		return false;
	}
	else
	{
		return false;
	}
}

// returns index of item if found, otherwise -1
int findListItem(const List* list, CPData data)
{
	if (list != NULL && data != NULL)
	{
		int position = 0;
		ListItem* current = list->first;
		while (current != NULL)
		{
			if (list->compareData(current->data, data) == 0)
			{
				return position;
			}
			else
			{
				position++;
				current = current->next;
			}
		}
	}
	return -1;
}

// returns index of equal item if found, otherwise index of first larger item, if none found: -1
// paramter data: input: the data to find. After execution: the data at the index returned
int findEqualOrFirstLargerListItem(const List* list, CPData* pcpData)
{
	CPData cpData = *pcpData;
	if (list != NULL && cpData != NULL)
	{
		int position = 0;
		ListItem* current = list->first;
		while (current != NULL)
		{
			if (list->compareData(current->data, cpData) >= 0)
			{
				pcpData = &(current->data);
				return position;
			}
			else
			{
				position++;
				current = current->next;
			}
		}
	}
	return -1;
}
