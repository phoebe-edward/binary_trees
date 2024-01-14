#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find its uncle
 * Return: pointer to uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: a pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return (node == node->parent->left ?
		node->parent->right : node->parent->left);
}
