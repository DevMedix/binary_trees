#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_node - a function that creates a binary tree node
 * @parent: parent node
 * @value: value of a node
 *
 * Return: returns the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
