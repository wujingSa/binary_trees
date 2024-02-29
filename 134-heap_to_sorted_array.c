#include "binary_trees.h"

/**
 * count_h_nodes - Counts the number of nodes in a binary tree
 * @root: Pointer to the root node of the binary tree
 *
 * This function recursively counts the number of nodes in a binary tree.
 * It returns the total number of nodes.
 *
 * Return: Number of nodes in the binary tree
 */
int count_h_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_h_nodes(root->left) +
		    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - Creates a sorted array from a max heap
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 *
 * Return: Pointer to array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nodes = count_h_nodes(heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}

