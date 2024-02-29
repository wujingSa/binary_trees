#include "binary_trees.h"
/**
 * bst_search - Function to find a node in a tree.
 * @tree: Root of the tree to evaluate.
 * @value: Value of the node to find.
 * Return: 1 if the node exists, 0 otherwise.
 */

bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
	return (NULL);
}
