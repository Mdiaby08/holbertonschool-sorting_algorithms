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
 * forward_pass - Goes left to right, bubbling the max to the end
 *
 * @list: Pointer to the head of the list
 * @top: Node where the right boundary stops
 * @swapped: Pointer to the swap flag, set to 1 if a swap occurred
 *
 * Return: The last node reached (new right boundary)
 */
static listint_t *forward_pass(listint_t **list, listint_t *top,
				int *swapped)
{
	listint_t *cur;

	cur = *list;
	while (cur->next != top)
	{
		if (cur->n > cur->next->n)
		{
			swap_nodes(list, cur, cur->next);
			print_list(*list);
			*swapped = 1;
		}
		else
			cur = cur->next;
	}
	return (cur);
}

/**
 * backward_pass - Goes right to left, bubbling the min to the front
 *
 * @list: Pointer to the head of the list
 * @bot: Node where the left boundary stops
 * @cur: Starting node (rightmost unsorted)
 * @swapped: Pointer to the swap flag, set to 1 if a swap occurred
 *
 * Return: The last node reached (new left boundary)
 */
static listint_t *backward_pass(listint_t **list, listint_t *bot,
				listint_t *cur, int *swapped)
{
	while (cur->prev != bot)
	{
		if (cur->n < cur->prev->n)
		{
			swap_nodes(list, cur->prev, cur);
			print_list(*list);
			*swapped = 1;
		}
		else
			cur = cur->prev;
	}
	return (cur);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using cocktail shaker sort
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *top;
	listint_t *bot;
	listint_t *cur;

	if (!list || !*list || !(*list)->next)
		return;

	top = NULL;
	bot = NULL;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		cur = forward_pass(list, top, &swapped);
		top = cur;
		if (!swapped)
			break;
		swapped = 0;
		bot = backward_pass(list, bot, cur, &swapped);
	}
}
