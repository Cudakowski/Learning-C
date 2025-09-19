#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Defines CMP as pointer to comparison function that returns:
 * - negative int value if the first argument to compare is "less" than the second,
 * - positive int value if the first argument to compare is "greater" than the second,
 * - 0 otherwise (the arguments are equivalent).
 * "Arguments to compare" are pointed by the parameters of the function.
 */
typedef int (*CMP)(const void *, const void *);

/**
 * @brief Defines PRINT as pointer to function that
 * prints the content of an element, to which the parameter points.
 */
typedef void (*PRINT)(const void *);

/**
 * @brief Node structure containing:
 * - data - pointer to data stored in the node,
 * - next - pointer to the next node in the list.
 */
typedef struct _Node
{
    void *data;
    struct _Node *next;
} Node;

/**
 * @brief Sorted list structure that contains the only information that is needed to enter the list:
 * head - pointer to the first node in the list. The list is sorted, so head points to the smallest node (in terms of comparison function).
 */
typedef struct _SortedList
{
    Node *head;
} SortedList;

/**
 * @brief Initializes the empty sorted list.
 *
 * @param list pointer to the list that should be initialized as an empty list.
 */
void initialize_list(SortedList *list);

/**
 * @brief Adds a new element to the sorted list.
 *
 * @param list pointer to the list.
 * @param data pointer to the new data that should be stored in the list.
 * @param cmp pointer to the comparison function.
 */
void add(SortedList *list, void *data, CMP cmp);

/**
 * @brief Removes the first element (node) that is equivalent to the data in terms of the comparison function.
 *
 * @param list pointer to the list.
 * @param cmp pointer to the comparison function.
 * @param data pointer to the data that should be removed from the list.
 */
void remove_data(SortedList *list, CMP cmp, void *data);

/**
 * @brief Removes all list elements (nodes).
 *
 * @param list pointer to the list.
 */
void remove_all(SortedList *list);

/**
 * @brief Get the data object
 *
 * @param list pointer to the list.
 * @param cmp pointer to the comparison function.
 * @param data pointer to the data to find.
 * @return void* pointer to the data stored in one of the element (node) of the list that is equivalent to the data passed as an argument (in terms of the comparison function).
 */

void *get_data(const SortedList *list, CMP cmp, const void *data);

/**
 * @brief Prints all the data stored in the list to stdout.
 *
 * @param list pointer to the list.
 * @param print pointer to function that prints the content of the data stored in an element (node) of the list.
 */
void print_list(const SortedList *list, PRINT print);

void merge_lists(SortedList *list1, SortedList *list2, SortedList *target, CMP cmp);

#endif
