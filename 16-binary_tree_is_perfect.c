#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 or 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h, size;

	if (!tree)
		return (0);
	h = binary_tree_height(tree);
	size = binary_tree_size(tree);
	if (my_pow(2, h + 1) - 1 == (int)size)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: the size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
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

/**
 * my_pow - calculates the power of two numbers
 * @num1: base
 * @num2: power
 * Return: the result of power operation
 */
int my_pow(int num1, int num2)
{
	if (num2 == 0)
		return (1);
	return (num1 * my_pow(num1, num2 - 1));
}
