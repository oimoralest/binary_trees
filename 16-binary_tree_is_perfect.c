#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree:  pointer to the root node of the tree to count the number of leaves
 * Return: the  number of the leaves or 0 on failure
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
	{
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
		return (leaves);
	}
}
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
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: the number of nodes with at least 1 child or 0 in failure
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (1 + binary_tree_nodes(tree->left)
	+ binary_tree_nodes(tree->right));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves = 0, height = 0, leaves2 = 1, i = 0, nodes = 0, nodes2 = 1;

	leaves = binary_tree_leaves(tree);
	height = binary_tree_height(tree);
	while (i < height)
		leaves2 *= 2, i++;
	nodes = binary_tree_nodes(tree);
	i = 0;
	while (i < height + 1)
		nodes2 *= 2, i++;
	nodes2 -= 1;
	if (leaves == leaves2 && nodes == nodes2)
		return (1);
	return (0);
}
