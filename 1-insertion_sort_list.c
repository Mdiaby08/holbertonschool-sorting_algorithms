#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;

while (current)
{
tmp = current;
while (tmp->prev && tmp->prev->n > tmp->n)
{
/* Swap nodes */
listint_t *prev = tmp->prev;

prev->next = tmp->next;
if (tmp->next)
tmp->next->prev = prev;

tmp->prev = prev->prev;
tmp->next = prev;

if (prev->prev)
prev->prev->next = tmp;
else
*list = tmp;

prev->prev = tmp;

print_list(*list);
}
current = current->next;
}
}
