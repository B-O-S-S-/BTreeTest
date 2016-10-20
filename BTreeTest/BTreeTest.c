// BTreeTest.c : Defines the entry point for the console application.
//

#include "stdafx.h"

int stringComparator(void* first, void* second)
{
	return strcmp((char*)first, (char*)second);
}

int main(int argc, char** args)
{
	if (argc < 2)
	{
		printf("Enter some strings to insert");
	}
	else
	{
		printf("Inserting args: ");
		for (int i = 1; i < argc; i++)
		{
			printf(" %s", args[i]);
		}

		// Test the list implementation

		List testList;
		testList.first = NULL;
		testList.count = 0;
		testList.compareData = &stringComparator;

		// test adding items
		bool result = true;
		for (int i = 1; i < argc; i++)
		{
			result = addListItem(&testList, (void*)args[i]);
			printf("\nAdding %s %s.", args[i], result ? "succeeded" : "failed");
		}

		if (result)
		{
			// insertion test succeeded, test search
			// start at args[0] to test search for nonexisting items
			for (int i = 0; i < argc; i++)
			{
				int idx = findListItem(&testList, (void*)args[i]);
				printf("\n%s %s at position %d", idx >= 0 ? "Found" : "Did not find", args[i], idx);
			}

			// test deleting all items including nonexistent

			for (int i = 0; i < argc; i++)
			{
				result = removeListItem(&testList, (void*)args[i]);
				printf("\nRemoving %s from list %s.", args[i], result ? "succeeded" : "failed");
			}
		}
		else
		{
			printf("Error occurred during insertion\n");
			return 1;
		}
	}
	return 0;
}
