#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree:  pointer to the root node of the tree to check
 * Return: 1 on success or 0 on failure
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 0;

	if (!tree)
		return (0);
	else if (tree->right && tree->left)
	{
		full = binary_tree_is_full(tree->left);
		full = binary_tree_is_full(tree->right);
		return (full);
	}
	else if (!tree->right && !tree->left)
		return (1);
	else
		return (0);
}
