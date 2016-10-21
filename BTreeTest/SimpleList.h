#pragma once
#include "stdafx.h"

typedef void* PData;
typedef const PData CPData;

typedef struct SortedDLListItem
{
	CPData data;
	struct SortedDLListItem *prev, *next;

} ListItem;

typedef struct SortedDLList
{
	ListItem* first;
	unsigned int count;
	int(*compareData)(CPData, CPData);
} List;

bool addListItem(List* list, CPData data);
bool removeListItem(List* list, CPData data);
int findListItem(const List* list, CPData data); // return position of item or -1 if not present
int findEqualOrFirstLargerListItem(const List* list, CPData* pcpData);

