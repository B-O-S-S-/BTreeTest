#pragma once
#include "stdafx.h"

typedef struct SortedDLListItem
{
	void* data;
	struct SortedDLListItem *prev, *next;

} ListItem;

typedef struct SortedDLList
{
	ListItem* first;
	unsigned int count;
	int(*compareData)(void*, void*);
} List;

bool addListItem(List* list, void* data);
bool removeListItem(List* list, void* data);
int findListItem(List* list, void* data); // return position of item or -1 if not present
