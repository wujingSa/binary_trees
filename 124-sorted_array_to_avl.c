#include "binary_trees.h"
/**
 * aux_sort - Recursively creates an AVL tree using half elements of the array.
 * @parent: The parent of the node to create.
 * @array: The sorted array.
 * @begin: The position where the array starts.
 * @last: The position where the array ends.
 * Return: The AVL tree created.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array.
 * @array: The sorted array.
 * @size: The size of the sorted array.
 * Return: The AVL tree formed from the sorted array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
