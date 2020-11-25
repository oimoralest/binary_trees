#include "binary_trees.h"
/**
 * height - measures the height of a binary tree
 * @tree: pointer to the tree to find its height
 * @i: iterator
 * Return: the height of the tree
 */
size_t height(const binary_tree_t *tree, size_t i)
{
	size_t leftDepth = 0, rightDepth = 0;

	if (!tree)
		return (i);
	i++;
	leftDepth = height(tree->left, i);
	rightDepth = height(tree->right, i);
	if (leftDepth > rightDepth)
		return (leftDepth);
	return (rightDepth);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor or 0 on failure
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree->left, 0) - height(tree->right, 0));
}
