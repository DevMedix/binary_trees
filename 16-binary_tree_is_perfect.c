#include "binary_trees.h"
/**
* count_nodes - counts the number of nodes in the tree
* @tree: pointer to root node of the binary tree
* Return: number of nodes
*/
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
* tree_height - measures the height of the binary tree
* @tree: pointer to the root node of the binary tree
* Return: the height of the tree
*/
int tree_height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree == NULL)
		return (0);

	l = tree_height(tree->left);
	r = tree_height(tree->right);

	return ((l > r) ? l + 1 : r + 1);
}

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the binary tree
* Return: 1 if tree is perfect and 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0;
	int node_count = 0;
	int expected_node_count = 0;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);
	node_count = count_nodes(tree);

	expected_node_count = (1 << height) - 1;

	if (node_count == expected_node_count)
		return (1);

	return (0);
}