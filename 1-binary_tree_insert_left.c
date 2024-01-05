#include "binary_trees.h"
/**
 * binary_tree_insert_left - insert a binary tree node in the left
 * @parent: pointer to parent node
 * @value: integer value
 * Return: pointer to node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL, *temp = NULL;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL || parent == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (parent->left)
	{
		temp = parent->left;
		parent->left = node;
		node->left = temp;
		temp->parent = node;
	}
	else
	{
		parent->left = node;
	}
	return (node);
}
