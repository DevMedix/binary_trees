#include "binary_trees.h"
#include <stdbool.h>

/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to the root of the binary tree
* Return: 1 if tree is complete and 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
    bool flag = false;
    int count = 0, front = 0, back = 0;
    binary_tree_t **queue, *current;

    if (tree == NULL)
        return (0);

    queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *) * 1000);
    if (queue == NULL)
        return (0);

    queue[back++] = (binary_tree_t *)tree;

    while (front < back)
    {
        current = queue[front++];
        count++;
        if (current->left != NULL)
        {
            if (flag == true)
                return (0);
            queue[back++] = current->left;
        }
        else
            flag = true;

        if (current->right != NULL)
        {
            if (flag == true)
                return (0);
            queue[back++] = current->right;
        }
        else
            flag = true;
    }

    free(queue);

    return (1);
}