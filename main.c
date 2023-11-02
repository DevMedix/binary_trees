#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int perfect;

    root = binary_tree_node(NULL, 98);
    perfect = binary_tree_is_perfect(root);
    printf("is the tree with root node (%d) Perfect? %d\n", root->n, perfect);

    binary_tree_print(root);

	binary_tree_delete(root);
    return (0);
}
