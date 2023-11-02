#include "binary_trees.h"

/**
* struct QueueNode - Queue node
*
* @tree_node: points to a binary tree node
* @next: pointer to the next node on the queue
*/
typedef struct QueueNode
{
	binary_tree_t *tree_node;
	struct QueueNode *next;
} QueueNode;

/**
* struct Queue - Queue
* @front: node after
* @back: node before
*/
typedef struct Queue
{
	QueueNode *front, *back;
} Queue;

/**
* newQueueNode - a node queue
* @tree: pointer to a tree node
* Return: a queue node
*/
QueueNode *newQueueNode(binary_tree_t *tree)
{
	QueueNode *temp;

	temp = malloc(sizeof(QueueNode));
	temp->tree_node = tree;
	temp->next = NULL;

	return (temp);
}

/**
* createQueue - creates a queue for the node
*
* Return: pointer to the queue
*/
Queue *createQueue(void)
{
	Queue *q = malloc(sizeof(Queue));
	q->front = q->back = NULL;

	return (q);
}

/**
* enQueue - adds a node to the queue
* @tree: pointer to the binary tree
* Return: void
*/
void enQueue(Queue *q, binary_tree_t *tree)
{
	QueueNode *temp;

	temp = newQueueNode(tree);

	if (q->back == NULL)
	{
		q->front = q->back = temp;
		return;
	}
}

/**
* deQueue - removes node from queue
* @q: pointer to the node
* Return: pointer to the queue
*/
QueueNode *deQueue(Queue *q)
{
	QueueNode *temp;

	if (q->front == NULL)
		return (NULL);

	temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->back = NULL;

	return (temp);
}

/**
* binary_tree_levelorder - goes through a binary tree using level
* order traversal
* @tree: pointer to the root node of the tree
* @func: pointer to a called function using the node data
* Return: nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	Queue *queue;
	QueueNode *current;

	if (tree == NULL || func == NULL)
		return;

	queue = createQueue();
	enQueue(queue, (binary_tree_t *)tree);

	while (queue->front != NULL)
	{
		current = deQueue(queue);
		func(current->tree_node->n);

		if (current->tree_node->left != NULL)
			enQueue(queue, current->tree_node->left);

		if (current->tree_node->right != NULL)
			enQueue(queue, current->tree_node->right);

		free(current);
	}
	free(queue);
}