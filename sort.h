#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element
 * @next: Pointer to the next element
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Provided printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Mandatory sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Advanced sorting algorithms */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/**
 * enum kind_e - Card suits
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
SPADE = 0,
HEART,
CLUB,
DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card
 * @kind: Suit of the card
 */
typedef struct card_s
{
const char *value;
const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of cards node
 * @card: Pointer to the card
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct deck_node_s
{
const card_t *card;
struct deck_node_s *prev;
struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* SORT_H */
