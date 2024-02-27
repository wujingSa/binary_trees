#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right child.
 * @parent: Pointer to the node to insert the right child into.
 * @value: The value to store in the new node.
 * Return: Return a pointer to the created node, or NULL on failure or if none.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (parent->right == NULL)
		parent->right = node;
	else
	{
		node->right = parent->right;
		parent->right = node;
		node->right->parent = node;
	}
	return (node);
}
