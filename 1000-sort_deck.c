#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * card_value - Returns the numeric value of a card (0 = Ace, 12 = King)
 *
 * @value: The string value of the card
 *
 * Return: Integer rank from 0 to 12
 */
static int card_value(const char *value)
{
	int i;
	const char *ranks[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
	};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, ranks[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * cmp_cards - Comparison function for qsort
 *
 * @a: Pointer to first deck_node_t pointer
 * @b: Pointer to second deck_node_t pointer
 *
 * Return: Negative, zero, or positive integer
 */
static int cmp_cards(const void *a, const void *b)
{
	const deck_node_t *na;
	const deck_node_t *nb;
	int kind_diff;

	na = *(const deck_node_t **)a;
	nb = *(const deck_node_t **)b;

	kind_diff = (int)na->card->kind - (int)nb->card->kind;
	if (kind_diff != 0)
		return (kind_diff);

	return (card_value(na->card->value) - card_value(nb->card->value));
}

/**
 * sort_deck - Sorts a deck of 52 cards from Ace to King, Spades to Diamonds
 *
 * @deck: Pointer to the head of the doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *ptrs[52];
	deck_node_t *cur;
	size_t i;

	if (!deck || !*deck)
		return;

	cur = *deck;
	for (i = 0; i < 52; i++)
	{
		ptrs[i] = cur;
		cur = cur->next;
	}

	qsort(ptrs, 52, sizeof(deck_node_t *), cmp_cards);

	for (i = 0; i < 52; i++)
	{
		ptrs[i]->prev = (i > 0) ? ptrs[i - 1] : NULL;
		ptrs[i]->next = (i < 51) ? ptrs[i + 1] : NULL;
	}

	*deck = ptrs[0];
}
