#include "binary_trees.h"

/**
* tree_height - measures the height of the binary tree
* @tree: pointer to the root node of the binary tree
* Return: the height of the tree
*/
int tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = tree_height(tree->left);
	int right_height = tree_height(tree->right);

	return ((left_height > right_height) ?
			left_height + 1 : right_height + 1);
}

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
 * linkedNode - this function makes a linked list from depth level and node
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linkedNode(linked_t **head, const binary_tree_t *tree, size_t level)
{
	linked_t *new, *temp;

	new = malloc(sizeof(linked_t));
	if (new == NULL)
		return;

	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new->next = NULL;
		temp->next = new;
	}
}

/**
 * recursion - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: Nothing by default it affects the pointer
 */
void recursion(linked_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = depth(tree);
		linkedNode(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0, count = 0;
	linked_t *head, *temp;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height(tree);
	head = NULL;
	recursion(&head, tree);

	while (count <= height)
	{
		temp = head;
		while(temp != NULL)
		{
			if (count == temp->n)
				func(temp->node->n);

			temp = temp->next;
		}
		count++;
	}

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}