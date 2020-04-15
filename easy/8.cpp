/*
#20 - EASY
This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node.The lists are non - cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time(where M and N are the lengths of the lists) and constant space.

Date: 08/04/2020
Dev Time: 20h45 - 

*/

typedef struct linked_list
{
	int value;
	struct linked_list* next;
}linked_list_t;

linked_list_t* list_A = NULL;
linked_list_t* list_B = NULL;
linked_list_t* list_C = NULL;

void AddItem(linked_list** list, int item)
{
	if (*list == NULL)
	{
		*list = new(linked_list_t);
		(*list)->value = item;
		(*list)->next = NULL;
	}
	else
		AddItem(&(*list)->next, item);
}

void AddList(linked_list** list, linked_list* item)
{
	if (*list == NULL)
	{
		*list = item;
	}
	else
		AddList(&(*list)->next, item);
}

void RemoveItem(linked_list *list, int item)
{
// No time to create a removal function
}

void ClearList(linked_list** list)
{
	if (*list != NULL)
	{
		ClearList(&(*list)->next);
		delete *list;
		*list = NULL;
	}
}

linked_list* FindItem(linked_list* list, int item)
{
	if (list != NULL)
	{
		if (list->value == item)
			return list;
		else
			return FindItem(list->next, item);
	}

	return NULL;
}

int FindIntersect(linked_list* A, linked_list* B)
{
	linked_list *intersect;

	if ((A == NULL) || (B == NULL))
		return -1;

	for (linked_list* it = A; it != NULL; it = it->next)
	{
		intersect = FindItem(B, it->value);

		if (intersect != NULL)
			return intersect->value;
	}

	return -1;
}

void CreateLists(void)
{
	// A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
	AddItem(&list_C, 8);
	AddItem(&list_C, 10);

	AddItem(&list_A, 3);
	AddItem(&list_A, 7);
	AddList(&list_A, list_C);

	AddItem(&list_B, 99);
	AddItem(&list_B, 1);
	AddList(&list_B, list_C);
}