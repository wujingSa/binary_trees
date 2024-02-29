#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap from an array.
 *
 * @array: Pointer to the first element of the array.
 * @size: The number of elements in the array.
 * Return: Pointer to the root node of the AVL tree.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree;
	size_t i;

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}

	return (tree);
}
