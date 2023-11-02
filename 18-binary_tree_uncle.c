#include "binary_trees.h"
/**
* binary_tree_uncle - returns the uncle to the binary tree node
* @node: pointer to node to find uncle
* Return: uncle to node
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grand_parent = parent->parent;

	if (grand_parent->left == parent)
		return (grand_parent->right);

	return (grand_parent->left);
}
