#include "binary_trees.h"
/**
* tree_height - calculates the height of the binary tree
* @tree: pointer to the root node of the binary tree
* Return: height of the tree
*/
int tree_height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	
	return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}

/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: mpointer to root node of the binary tree
* Return: The balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (left_height - right_height);
}
