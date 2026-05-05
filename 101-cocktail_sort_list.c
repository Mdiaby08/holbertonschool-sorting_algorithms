#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @a: Left node (comes before b)
 * @b: Right node (comes after a)
 */
static void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using cocktail shaker sort
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *cur;
	listint_t *top;
	listint_t *bot;

	if (!list || !*list || !(*list)->next)
		return;

	top = NULL;
	bot = NULL;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		cur = *list;
		while (cur->next != top)
		{
			if (cur->n > cur->next->n)
			{
				swap_nodes(list, cur, cur->next);
				print_list(*list);
				swapped = 1;
			}
			else
				cur = cur->next;
		}
		top = cur;
		if (!swapped)
			break;
		swapped = 0;
		while (cur->prev != bot)
		{
			if (cur->n < cur->prev->n)
			{
				swap_nodes(list, cur->prev, cur);
				print_list(*list);
				swapped = 1;
			}
			else
				cur = cur->prev;
		}
		bot = cur;
	}
}
