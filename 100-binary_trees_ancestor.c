#include "binary_trees.h"
/**
* depth - returns the distance from node to root
* @node: pointer to node to find depth
* Return: the depth of the node
*/

int depth(const binary_tree_t *node)
{
	int depthVal = 0;

	while (node != NULL)
	{
		depthVal++;
		node = node->parent;
	}

	return (depthVal);
}

/**
* binary_trees_ancestor - returns the lowest common amcestor of
* two binary tree nodes
* @first: pointer to the first node
* @second: pointer to second node
* Return: pointer to the common ancestor
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = depth(first);
	second_depth = depth(second);

	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}

	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}

	while (first != second && first != NULL && second != NULL)
	{
		first = first->parent;
		second = second->parent;
	}

	if (first == NULL || second == NULL)
		return (NULL);

	return ((binary_tree_t *)first);
}