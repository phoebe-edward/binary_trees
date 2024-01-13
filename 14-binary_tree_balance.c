#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
	{
		height_l = 0;
		height_r = 0;
	}
	else if (tree->left == NULL)
	{
		height_l = 0;
		height_r = 1 + binary_tree_height(tree->right);
	}
	else if (tree->right == NULL)
	{
		height_l = 1 + binary_tree_height(tree->left);
		height_r = 0;
	}
	else
	{
		height_l = 1 + binary_tree_height(tree->left);
		height_r = 1 + binary_tree_height(tree->right);
	}
	return (height_l - height_r);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: tree height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if (tree->left == NULL)
	{
		r_height = (1 + binary_tree_height(tree->right));
		l_height = 0;
	}
	else if (tree->right == NULL)
	{
		l_height = (1 + binary_tree_height(tree->left));
		r_height = 0;
	}
	else
	{
		l_height = (1 + binary_tree_height(tree->left));
		r_height = (1 + binary_tree_height(tree->right));
	}
	if (l_height > r_height)
		return (l_height);
	else
		return (r_height);
}
