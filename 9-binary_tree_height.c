#include "binary_trees.h"
/**
 * max_depth - finds the max depth of a tree's branch
 * @tree: pointer to the branch to find the depth
 * @i: counter
 * Return: Max depth of the branch
 */
size_t max_depth(const binary_tree_t *tree, size_t i)
{
	size_t leftDepth = 0, rightDepth = 0;

	if (!tree)
		return (i);
	i++;
	leftDepth = max_depth(tree->left, i);
	rightDepth = max_depth(tree->right, i);
	if (leftDepth > rightDepth)
		return (leftDepth);
	return (rightDepth);

}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the tree or 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftDepth = 0, rightDepth = 0;

	if (!tree)
		return (0);
	leftDepth = max_depth(tree->left, 0);
	rightDepth = max_depth(tree->right, 0);
	if (leftDepth > rightDepth)
		return (leftDepth);
	return (rightDepth);
}
