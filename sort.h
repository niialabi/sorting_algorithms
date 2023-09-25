#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomu_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
#endif
