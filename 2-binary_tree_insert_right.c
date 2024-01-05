#include "binary_trees.h"
/**
 * binary_tree_insert_right - insert a binary tree node in the right
 * @parent: pointer to parent node
 * @value: integer value
 * Return: pointer to node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL, *temp = NULL;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (parent->right)
	{
		temp = parent->right;
		parent->right = node;
		node->right = temp;
		temp->parent = node;
	}
	else
	{
		parent->right = node;
	}
	return (node);
}
