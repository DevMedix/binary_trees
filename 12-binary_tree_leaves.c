#include "binary_tree.h"
/**
* binary_tree_leaves - counts the number of leaves in the binary tree
* @tree: pointer to the root node of the binary tree
*
* Return: number of leaves or 0 if unsuccessful
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		leaves += 1;

	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);

	return (leaves);
}
