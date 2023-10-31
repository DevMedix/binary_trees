#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: pointer to the root of the tree to measure the height
 *
 * Return: returns 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight;
	size_t rightHeight;

	if (tree == NULL)
		return 0;

	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);

	if (leftHeight > rightHeight)
		return (leftHeight + 1);
	else
		return (rightHeight + 1);
}
