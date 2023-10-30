#include "binary_tree.h"
/**
 * binary_tree_nodes - counts the nodes with at least one child
 * @tree: pointer to the root node of the binary tree
 *
 * Return: number of nodes with at least a child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		node += 1;

	node += binary_tree_nodes(tree->left);
	node += binary_tree_nodes(tree->right);

	return (node);
}
