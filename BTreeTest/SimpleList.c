#include "stdafx.h"

bool addListItem(List* list, void* data)	// add an item into a sorted list, smallest item first
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
				ListItem* newItem = (ListItem*)malloc(sizeof(ListItem));
				newItem->data = data;
				newItem->prev = current->prev;
				newItem->next = current;
				current->prev = newItem;
				if (prev == NULL) // new head
				{
					list->first = newItem;
				}
				else
				{
					prev->next = newItem;
				}
				list->count++;
				return true; // item inserted before the end
			}
			else // item already present
			{
				return false;
			}
		}
		ListItem* newItem = (ListItem*)malloc(sizeof(ListItem));
		newItem->data = data;
		newItem->prev = prev;
		newItem->next = NULL;
		if (prev == NULL) // empty list
		{
			list->first = newItem;
		}
		else // reached end of nonempty list
		{
			prev->next = newItem;
		}
		list->count++;
		return true;
	}
	else
	{
		return false;
	}
}

bool removeListItem(List* list, void* data)
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

int findListItem(List* list, void* data)
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
