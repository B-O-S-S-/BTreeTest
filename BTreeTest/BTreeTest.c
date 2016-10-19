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

		List testList;
		testList.first = NULL;
		testList.count = 0;
		testList.compareData = &stringComparator;

		bool result = true;
		for (int i = 1; i < argc; i++)
		{
			result = result && addListItem(&testList, (void*)args[i]);
		}
		printf("\ninsert result = %d\n", result);

		if (result)
		{
			/*for(int i = 1; i < argc; i++)
			{
			result = result && addListItem(&testList, (void*) args[i]);
			}*/
			int r2 = findListItem(&testList, args[1]);
			printf("Found %s at position %d\n", args[1], r2);
		}
		else
		{
			printf("Error occurred during insertion\n");
			return 1;
		}
	}
	return 0;
}
